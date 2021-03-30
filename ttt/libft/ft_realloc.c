/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:44:35 by araout            #+#    #+#             */
/*   Updated: 2019/01/25 10:44:35 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int newsize)
{
	char *output;

	output = ft_strnew(newsize);
	if (output)
		ft_strlcpy(output, str, newsize + 1);
	ft_strdel(&str);
	return (output);
}
