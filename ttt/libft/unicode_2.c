/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:39:48 by araout            #+#    #+#             */
/*   Updated: 2018/12/11 15:39:48 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_strlen_uni(int *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_uni_fd(int c, int fd)
{
	int tmp;

	if (ft_get_lastbit(c) <= 6)
		write(fd, &c, 1);
	else if (ft_get_lastbit(c) <= 10)
	{
		tmp = 0xC080 | (c & 0x3F);
		tmp = tmp | ((c & 0xfC0) << 2);
		c = (tmp & 0xFF00) >> 8;
		write(fd, &c, 1);
		c = tmp & 0xFF;
		write(fd, &c, 1);
	}
	else if (ft_get_lastbit(c) <= 15)
		print_three_bytes(c, fd);
	else
		print_four_bytes(c, fd);
}

int		ft_putstr_uni_fd(int *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar_uni_fd(str[i], fd);
		i++;
	}
	return (i);
}

int		ft_putnstr_uni_fd(int *str, int len, int fd)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar_uni_fd(str[i], fd);
		i++;
	}
	return (i);
}
