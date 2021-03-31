#ifndef __FT_PING__
# define __FT_PING__

# define ERR_FORMAT	0
# define ERR_PERM	1
# define ERR_SOCKET 2
					//ERROR GETADDRINFO
# define EAI_ADDRFAMILY	3	/* address family for host not supported */
# define EAI_AGAIN		4	/* temporary failure in name resolution */
# define EAI_BADFLAGS	5	/* invalid value for ai_flags */
# define EAI_FAIL		6	/* non-recoverable failure in name resolution */
# define EAI_FAMILY		7	/* ai_family not supported */
# define EAI_MEMORY		8	/* memory allocation failure */
# define EAI_NODATA		9	/* no address associated with host */
# define EAI_NONAME		10	/* host nor service provided, or not known */
# define EAI_SERVICE	11 /* service not supported for ai_socktype */
# define EAI_SOCKTYPE	12	/* ai_socktype not supported */
# define EAI_SYSTEM		13	/* system error returned in errno */

# define ERR_SETSOCKOPT	14
# define ERR_RECVMSG	15
# define ERR_SENDTO		16
# define ERR_OPTS		17
# define ERR_OPTT		18

# define ERR_MALLOC		19

# define OPT_V (1 << 0)
# define OPT_H (1 << 1)
# define OPT_S (1 << 2)
# define OPT_T (1 << 3)

# define ROOT 0

# define BUFSIZE 1024
# define PACKETSIZE 64

#define HTONS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#define NTOHS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))

#define HTONL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))

#define NTOHL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))

#define NTOHL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))



# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <sys/time.h>
# include <netinet/in_systm.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <errno.h>


typedef struct		s_env
{
		unsigned int	opt;
		char			host_str[64];
		char			*arg;
		uint64_t		time;
		uint64_t		total_time;
		uint64_t		delay;
		int				recvd_nb;
		int				ttl;
		int				seq;
		int				data_size;
		pid_t			pid;
}	t_env;

typedef struct		s_pack
{
	struct icmphdr	icmph;
	char			data[2048];
}t_pack;

typedef struct		s_ping
{
	int				sfd;
	int				sent;
	int				recv;
	char			recv_buf[BUFSIZE];
	t_env			env;
	t_pack			packet;
	struct msghdr	recv_msg;
	struct addrinfo *h_addrinfo;

} t_ping;

t_ping		g_ping;

void			err(int);

#endif
