/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:14:04 by modaouch          #+#    #+#             */
/*   Updated: 2019/04/25 20:17:08 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(const char *str, size_t n)
{
	char	*dest;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(str);
	if (!(dest = (char *)ft_memalloc(sizeof(*dest) * (i + 1))))
		return (0);
	while (j < i && n--)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}
