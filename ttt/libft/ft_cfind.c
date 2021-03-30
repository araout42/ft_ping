/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 00:06:39 by araout            #+#    #+#             */
/*   Updated: 2019/01/24 00:06:40 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c ? i : -1);
}

int		ft_rcfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
