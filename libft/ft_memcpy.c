/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:24:02 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 15:24:03 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*src;

	if (num != 0)
	{
		i = 0;
		dest = (unsigned char*)destination;
		src = (unsigned char*)source;
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (destination);
}
