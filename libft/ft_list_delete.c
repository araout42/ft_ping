/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2019/07/16 04:06:33 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void					ft_list_delete(t_list **list)
{
	t_list *tmp;

	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_strdel(((char **)&tmp->content));
		free(tmp);
	}
}
