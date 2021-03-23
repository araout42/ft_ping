/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *destination, const char *source)
{
	int i;
	int offset;

	if (destination == NULL || source == NULL)
		return (NULL);
	offset = 0;
	while (destination[offset] != '\0')
		offset++;
	i = 0;
	while (source[i] != '\0')
	{
		destination[offset + i] = source[i];
		i++;
	}
	destination[offset + i] = '\0';
	return (destination);
}
