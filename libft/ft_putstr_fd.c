/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:32:29 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 19:32:30 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr_fd(char const *s, int fd)
{
	size_t i;

	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}
