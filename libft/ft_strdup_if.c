/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_if(const char *s, int (*f)(int))
{
	int		i;
	int		len;
	char	*output;

	len = 0;
	while (s[len] && f(s[len]))
		len++;
	output = (char*)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = s[i];
		i++;
	}
	output[len] = '\0';
	return (output);
}
