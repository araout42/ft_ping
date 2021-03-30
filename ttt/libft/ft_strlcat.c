/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t offset;
	size_t srclen;

	offset = 0;
	while (dst[offset] != '\0')
		offset++;
	i = 0;
	srclen = 0;
	while (src[i] != '\0' && offset + i < size - 1)
	{
		if (size != 0)
			dst[offset + i] = src[i];
		i++;
		srclen++;
	}
	if (size != 0)
		dst[offset + i] = '\0';
	while (src[srclen] != '\0')
		srclen++;
	if (size < offset)
		return (srclen + size);
	return (offset + srclen);
}
