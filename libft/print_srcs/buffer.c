/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 00:09:44 by araout            #+#    #+#             */
/*   Updated: 2019/03/04 00:09:45 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_buffer.h"
#include "libft.h"
#include <unistd.h>

void		write_buffer(int fd, char *str, int len)
{
	static char		buffer[PRINTF_BUFSIZE];
	static int		idx = 0;
	int				i;

	if (len == -99)
	{
		if (idx > 0)
			write(fd, buffer, idx);
		idx = 0;
		return ;
	}
	i = 0;
	while (i < len && idx < PRINTF_BUFSIZE)
	{
		buffer[idx] = str[i];
		++i;
		++idx;
	}
	if (idx == PRINTF_BUFSIZE)
	{
		write(fd, buffer, PRINTF_BUFSIZE);
		idx = 0;
		if (i != len)
			write_buffer(fd, str + i, len - i);
	}
}

int			ft_putchar_buffer(char c, int fd)
{
	write_buffer(fd, &c, 1);
	return (1);
}

size_t		ft_putstr_buffer(char *s, int fd)
{
	size_t i;

	if (s == NULL)
		return (ft_putstr_buffer("(null)", fd));
	i = ft_strlen(s);
	write_buffer(fd, s, i);
	return (i);
}

size_t		ft_putnstr_buffer(char *str, size_t n, int fd)
{
	size_t i;

	if (str == NULL)
		return (ft_putnstr_buffer("(null)", n, fd));
	i = 0;
	while (str[i] && i < n)
		i++;
	write_buffer(fd, str, i);
	return (i);
}

int			ft_print_char_buffer(char c, int amount, int fd)
{
	int n;

	n = amount;
	while (n-- > 0)
		ft_putchar_buffer(c, fd);
	return (ft_floor(0, amount));
}
