/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charset_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:16:09 by araout            #+#    #+#             */
/*   Updated: 2019/01/25 10:16:09 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_match_charset(char *charset, char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (charset[i] && charset[i] != *str)
			++i;
		if (charset[i] == '\0')
			return (0);
		++str;
	}
	return (1);
}

int		charset_match(char *charset, char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (charset[i] && charset[i] == *str)
			++i;
		if (charset[i] != '\0')
			return (0);
		++str;
	}
	return (1);
}
