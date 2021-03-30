/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:58:21 by araout            #+#    #+#             */
/*   Updated: 2018/12/03 21:58:22 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

t_spec	*spec_lst_new(int idx)
{
	t_spec	*tmp;

	if ((tmp = (t_spec*)ft_memalloc(sizeof(t_spec))) == NULL)
		return (NULL);
	ft_bzero(tmp, sizeof(t_spec));
	tmp->print = 1;
	tmp->idx = idx;
	tmp->fd = 1;
	return (tmp);
}

void	spec_lst_push(t_spec **begin_list, t_spec *spec)
{
	t_spec *tmp;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = spec;
	else
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = spec;
	}
}

t_spec	*spec_lst_clear(t_spec *lst)
{
	t_spec *tmp;

	tmp = lst->next;
	ft_strdel(&(lst->minlen));
	ft_strdel(&(lst->maxlen));
	free(lst);
	return (tmp);
}
