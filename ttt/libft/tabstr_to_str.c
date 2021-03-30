/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modaouch <modaouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:02:37 by modaouch          #+#    #+#             */
/*   Updated: 2019/04/25 20:15:18 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*tabstr_to_str(char **tab, char *sep)
{
	char		*str;
	int			i;

	i = 0;
	str = ft_strdup(tab[i++]);
	while (str && tab[i])
	{
		if (sep)
			str = ft_strjoin_free(str, sep, 1);
		str = ft_strjoin_free(str, tab[i++], 1);
	}
	return (str);
}
