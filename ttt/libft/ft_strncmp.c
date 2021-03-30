/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 07:09:23 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned int i;

	i = 0;
	while ((unsigned int)(str1[i]) && i < num
			&& (unsigned int)(str1[i]) == (unsigned int)(str2[i]))
		i++;
	if (i == num)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int		ft_strncmp_case(const char *str1, const char *str2, size_t num)
{
	unsigned int i;

	i = 0;
	while ((unsigned int)(str1[i]) && i < num
			&& ft_tolower(str1[i]) == ft_tolower(str2[i]))
		i++;
	if (i == num)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
