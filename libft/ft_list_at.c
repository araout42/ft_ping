/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 01:55:14 by araout            #+#    #+#             */
/*   Updated: 2019/05/08 01:55:14 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_at(t_list *list, unsigned int idx)
{
	while (list != NULL)
	{
		if (idx-- == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
