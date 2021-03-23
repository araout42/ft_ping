/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2019/07/20 11:07:30 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int result;
	int i;
	int mult;

	if (str == 0)
		return (0);
	i = 0;
	result = 0;
	mult = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' \
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * mult);
}

unsigned int	ft_atoui(const char *str)
{
	unsigned int	result;
	int				i;

	if (str == 0)
		return (0);
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' \
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		++i;
	if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result);
}
