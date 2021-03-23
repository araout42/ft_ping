/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:48:54 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 15:48:55 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int character)
{
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != character)
	{
		i++;
	}
	if (str[i] == character)
		return ((char*)str + i);
	return (0);
}
