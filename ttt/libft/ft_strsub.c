/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:08:46 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 19:08:46 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	output = (char*)ft_memalloc(len + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	output[len] = '\0';
	while (len--)
	{
		output[i] = s[start + i];
		i++;
	}
	return (output);
}
