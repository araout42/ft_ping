/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 05:09:13 by araout            #+#    #+#             */
/*   Updated: 2018/11/07 05:09:14 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtoupper(char *string)
{
	unsigned int	i;

	if (string == NULL)
		return (NULL);
	i = 0;
	while (string[i])
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
	return (string);
}
