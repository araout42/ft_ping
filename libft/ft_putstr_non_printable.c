/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:24:45 by araout            #+#    #+#             */
/*   Updated: 2018/11/25 07:24:46 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t		ft_putstr_non_printable(char *str)
{
	size_t	i;

	if (str == NULL)
		return (ft_putstr("(null)"));
	else
	{
		i = 0;
		while (str[i])
		{
			if (str[i] < 32 || str[i] > 126)
			{
				ft_putchar('\\');
				ft_print_hex(str[i], 2);
			}
			else
				ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}
