/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 00:17:31 by araout            #+#    #+#             */
/*   Updated: 2018/11/16 00:17:32 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoinfree(char *source, const char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else if (concat != NULL)
		tmp = ft_strjoin(source, concat);
	else
		return (ft_strdup(""));
	free(source);
	return (tmp);
}

char		*ft_strjoinfree_both(char *source, char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else if (concat != NULL)
		tmp = ft_strjoin(source, concat);
	else
		return (ft_strdup(""));
	free(source);
	free(concat);
	return (tmp);
}

char		*ft_strjoinfree_last(const char *source, char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else if (concat != NULL)
		tmp = ft_strjoin(source, concat);
	else
		return (ft_strdup(""));
	free(concat);
	return (tmp);
}
