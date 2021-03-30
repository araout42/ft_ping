/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:23:56 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 19:23:57 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	nbr_length(int nbr)
{
	int len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*output;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = nbr_length(n);
	output = ft_strnew(len);
	if (output == 0)
		return (0);
	output[0] = '0';
	if (n < 0)
		output[0] = '-';
	n = ft_abs(n);
	while (n != 0)
	{
		output[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (output);
}

void		ft_itoa_str(int n, char *str, unsigned int maxlen)
{
	int len;

	len = nbr_length(n);
	if (maxlen <= 1)
		return ;
	str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = 0;
	n = ft_abs(n);
	while (--maxlen != 0 && n != 0)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
}
