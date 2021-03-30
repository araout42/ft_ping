/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:53:51 by modaouch          #+#    #+#             */
/*   Updated: 2018/04/23 17:42:33 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char		*ft_multijoin(unsigned int nb, ...)
{
	va_list	params;
	char	*str;

	va_start(params, nb);
	str = ft_strdup(va_arg(params, char *));
	nb--;
	while (str && nb-- > 0)
	{
		if (!(str = ft_strjoin_free(str, va_arg(params, char *), 1)))
			break ;
	}
	va_end(params);
	return (str);
}
