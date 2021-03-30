/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2020/11/01 19:29:08 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t			ft_strlen(const char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t			ft_strclen(const char *s, char c)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}
