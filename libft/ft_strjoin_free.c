/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <modaouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:02:37 by modaouch          #+#    #+#             */
/*   Updated: 2019/04/25 20:15:18 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin_free(char *s1, char *s2, size_t option)
{
	char		*str;
	int			len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memmove(str, s1, ft_strlen(s1) + 1);
	ft_strncat(str, s2, ft_strlen(s2));
	if (option != 0)
	{
		if (option == 1 || option == 3)
			if (s1)
				free(s1);
		if (option == 2 || option == 3)
			if (s2)
				free(s2);
	}
	return (str);
}
