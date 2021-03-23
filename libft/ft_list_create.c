/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:09:22 by araout            #+#    #+#             */
/*   Updated: 2019/04/25 20:14:19 by modaouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list					*ft_list_create(char *content, size_t content_size)
{
	t_list *new;

	if ((new = ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = content;
	new->content_size = content_size;
	return (new);
}
