/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:02:39 by araout            #+#    #+#             */
/*   Updated: 2020/10/12 14:04:51 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*merge(t_list *a, t_list *b, int (*cmp)(t_list *a, t_list *b),
	t_list *head)
{
	t_list		**r;

	r = &head;
	if (a && b)
	{
		while (1)
		{
			if ((*cmp)(a, b) <= 0 && (*r = a))
			{
				r = &a->next;
				a = a->next;
				if (!a)
					break ;
			}
			else if ((*r = b) || 1)
			{
				r = &b->next;
				b = b->next;
				if (!b)
					break ;
			}
		}
	}
	*r = (a == NULL) ? b : a;
	return (head);
}

t_list		*mergesorti(t_list *p, int (*cmp)(t_list *a, t_list *b))
{
	t_list*a;
	t_list*b;
	t_list*last;

	b = p;
	a = b;
	last = NULL;
	while (a && a->next)
	{
		last = b;
		b = b->next;
		a = a->next->next;
	}
	if (last == NULL)
		return (p);
	last->next = NULL;
	return (merge(mergesorti(p, cmp), mergesorti(b, cmp), cmp, NULL));
}
