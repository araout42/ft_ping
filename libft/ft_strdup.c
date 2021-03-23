/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*output;

	if (s == NULL || (output = (char*)ft_memalloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strcdup(const char *s, char c)
{
	int		i;
	char	*output;

	if (!s || (output = (char*)ft_memalloc(ft_strclen(s, c) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strdup_del(const char *s, char *to_free)
{
	ft_strdel(&to_free);
	return (ft_strdup(s));
}
