/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:27:52 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 15:27:52 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	cmp;
	unsigned char	*dst;
	unsigned char	*source;

	if (n != 0)
	{
		i = 0;
		cmp = (unsigned char)c;
		dst = (unsigned char*)dest;
		source = (unsigned char*)src;
		while (i < n)
		{
			dst[i] = source[i];
			if (source[i] == cmp)
				return (dst + i + 1);
			i++;
		}
	}
	return (NULL);
}
