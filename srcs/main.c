#include <ft_ping.h>


uint16_t	checksum(uint16_t *buffer, uint32_t size) 
{
	unsigned long cksum=0;
	while(size >1) 
	{
		cksum+=*buffer++;
		size -=sizeof(unsigned short);
	}
	if(size ) 
	{
		cksum += *(unsigned char *)buffer;
	}
	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >>16);
	return (uint16_t)(~cksum);
}

static int		get_arg(int ac, char **av)
{
	int		i = 1;
	g_ping.env.arg = av[ac - i];

	while (++i < ac)
	{
		if (ft_strcmp(av[ac - i], "-v") == 0)
			g_ping.env.opt |= OPT_V;
		if (ft_strcmp(av[ac - i], "-h") == 0)
			g_ping.env.opt |= OPT_H;
	}
	return(1);
}

static void		get_host(void)
{
	struct addrinfo hints;
	struct addrinfo *ok;
	int				i;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	hints.ai_flags = 0;
	((i = getaddrinfo(g_ping.env.arg, NULL, &hints, &g_ping.h_addrinfo)) != 0) ? err(i) : 0;
	ok = g_ping.h_addrinfo;
	inet_ntop(ok->ai_family, (void *)&(((struct sockaddr_in*)(ok->ai_addr))->sin_addr), g_ping.env.host_str, 64);
	printf("%s\n", g_ping.env.host_str);
}

static void		set_sockopt(void)
{
	int opt = 1;
	if (setsockopt(g_ping.sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) != 0)
	opt = 64;
	if (setsockopt(g_ping.sfd, IPPROTO_IP, IP_TTL, &opt, sizeof(int)) != 0)
		err(ERR_SETSOCKOPT);
}

static void		init(void)
{
	
	g_ping.env.pid = getpid();
	gettimeofday((struct timeval *)&(g_ping.env.t_start), NULL);
	if ((g_ping.sfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
		err(ERR_SOCKET);
	set_sockopt();
	get_host();
}

static void		send_echo_req(int seq)
{
	uint16_t		tmp;
	struct icmphdr	*icmph;

	memset((void*)&g_ping.packet, 0, sizeof(g_ping.packet));
	icmph = &(g_ping.packet.icmph);
	icmph->type = 8;
	tmp = g_ping.env.pid;
	icmph->un.echo.id = (g_ping.env.pid >> 8) |  tmp;
	tmp = seq;
	icmph->un.echo.sequence = (seq >> 8) | tmp;
	icmph->checksum = checksum((uint16_t *)&g_ping.packet, sizeof(t_pack));
	if ((g_ping.sent = sendto(g_ping.sfd, (void *)&(g_ping.packet), sizeof(g_ping.packet), 0, (struct sockaddr *)&(g_ping.h_addrinfo->ai_addr), g_ping.h_addrinfo->ai_addrlen)) <= 0)
		err(ERR_SOCKET);
}

static void		ping(void)
{
	int		seq = 0;

	while (1)
	{
		seq++;
		send_echo_req(seq);
	}
}

int		main(int ac, char **av)
{
	if (ac < 2)
		err(ERR_FORMAT);
	if (getuid())
		err(ERR_PERM);
	memset(&g_ping, 0, sizeof(g_ping));
	get_arg(ac, av);
	init();
	ping();
	return(1);
}


void	err(int code)
{
	if (g_ping.sfd <= 1)
		close(g_ping.sfd);
	switch(code)
	{
		case ERR_FORMAT:
			printf("Error format, use ft_ping -h to see help message\n");
			break;
		case ERR_PERM:
			printf("Error uid non equal to 0\n");
			break;
		case EAI_ADDRFAMILY:
			printf("address family for host not supported\n");
			break;
		case EAI_AGAIN:
			printf("temporary failure in name resolution\n");
			break;
		case EAI_BADFLAGS:
			printf("invalid value for ai_flags\n");
			break;
		case EAI_FAIL:
			printf("non-recoverable failure in name resolution\n");
			break;
		case EAI_FAMILY:
			printf("ai_family not supported\n");
			break;
		case EAI_MEMORY:
			printf("memory allocation failure\n");
			break;
		case EAI_NODATA:
			printf("no address associated with host\n");
			break;
		case EAI_NONAME:
			printf("host nor service provided, or not known\n");
			break;
		case EAI_SERVICE:
			printf("service not supported for ai_socktype\n");
			break;
		case EAI_SOCKTYPE:
			printf("ai_socktype not supported\n");
			break;
		case EAI_SYSTEM:
			printf("system error returned in errno\n");
			break;
		case ERR_SOCKET:
			switch (errno)
			{
				case EACCES:
					printf("Permission to create a socket of the specified type and/or protocol is denied.\n");
					break;
				case EAFNOSUPPORT:
					printf("The implementation does not support the specified address family.\n");
					break;
				case EINVAL:
					printf("Unknown protocol, or protocol family not available or Invalid flags in type.\n");
					break;
				case EMFILE:
					printf("The per-process limit on the number of open file descriptors has been reached or The per-process limit on the number of open file escriptors has been reached.\n");
					break;
				case ENOBUFS || ENOMEM:
					printf("Insufficient memory is available. The socket cannot be created until sufficient resources are freed.\n");
					break;
				case EPROTONOSUPPORT:
					printf("The protocol type or the specified protocol is not supported within this domain.\n");
					break;
				case EAGAIN || EWOULDBLOCK:
					printf("The socket is marked nonblocking and the requested operation would block\n");
					break;
				case EALREADY:
					printf("Another Fast Open is in progress.\n");
					break;
				case EBADF:
					printf("sockfd is not a valid open file descriptor.\n");
					break;
				case ECONNRESET:
					printf("Connection reset by peer\n");
					break;
				case EDESTADDRREQ:
					printf("The socket is not connection-mode, and no peer address is set.\n");
					break;
				case EFAULT:
					printf("An invalid user space address was specified for an argument.\n");
					break;
				case EINTR:
					printf("A signal occurred before any data was transmitted\n");
					break;
				case EISCONN:
					printf("The connection-mode socket was connected already but a recipient was specified.\n");
					break;
				case EMSGSIZE:
					printf("The socket type requires that message be sent atomically, and the size of the message to be sent made this impossible.\n");
					break;


			}
		break;
		case ERR_SETSOCKOPT:
			switch(errno)
			{
				case EBADF:
					printf("The argument sockfd is not a valid descriptor.\n");
					break;
				case EFAULT:
					printf("The address pointed to by optval is not in a valid part of the process addres space.\n");
					break;
				case EINVAL:
					printf("optlen invalid in setsockopt()\n");
					break;
				case ENOPROTOOPT:
					printf("The option is unknown at the level indicated.\n");
					break;
				case ENOTSOCK:
					printf("The argument sockfd is a file, not a socket.\n");
					break;
			}
			break;
		default :
			printf("Error...");
	}
	exit(1);
}

