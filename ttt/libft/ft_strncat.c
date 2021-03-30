/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source, size_t num)
{
	unsigned int i;
	unsigned int offset;

	offset = 0;
	while (destination[offset] != '\0')
		offset++;
	i = 0;
	while (source[i] != '\0' && i < num)
	{
		destination[offset + i] = source[i];
		i++;
	}
	destination[offset + i] = '\0';
	return (destination);
}
