/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:50:10 by araout            #+#    #+#             */
/*   Updated: 2018/12/11 08:50:10 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int start, int end)
{
	int		len;

	if (str == NULL || start < 0 || end <= start)
		return (NULL);
	len = ft_strlen(str);
	if (start >= len || end > len)
		return (NULL);
	ft_strcpy(str + start, str + end);
	return (str);
}
