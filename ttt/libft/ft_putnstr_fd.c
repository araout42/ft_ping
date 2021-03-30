/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:29:52 by araout            #+#    #+#             */
/*   Updated: 2018/11/30 02:29:52 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_putnstr_fd(char *str, size_t n, int fd)
{
	size_t i;

	if (str == NULL)
		return (ft_putnstr_fd("(null)", n, fd));
	i = 0;
	while (str[i] && i < n)
		i++;
	write(fd, str, i);
	return (i);
}
