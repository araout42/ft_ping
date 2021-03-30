/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 07:17:53 by araout            #+#    #+#             */
/*   Updated: 2019/07/18 07:47:45 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ccount(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (c == *str)
			++count;
		++str;
	}
	return (count);
}