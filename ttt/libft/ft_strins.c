/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 05:47:20 by araout            #+#    #+#             */
/*   Updated: 2018/11/08 05:47:21 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(char *dest, const char *src, unsigned int pos)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	offset;

	if (dest == NULL || src == NULL)
		return (NULL);
	destlen = ft_strlen(dest);
	offset = ft_strlen(src);
	i = destlen + offset;
	while (i > pos)
	{
		dest[i] = dest[i - offset];
		i--;
	}
	i = 0;
	while (i < offset)
	{
		dest[pos + i] = src[i];
		i++;
	}
	dest[destlen + offset] = '\0';
	return (dest);
}

char	*ft_strnins(char *dest, const char *src, unsigned int count,
						unsigned int pos)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	offset;

	if (dest == NULL || src == NULL)
		return (NULL);
	destlen = ft_strlen(dest);
	offset = count;
	i = destlen + offset;
	while (i > pos)
	{
		dest[i] = dest[i - offset];
		i--;
	}
	i = 0;
	while (i < offset)
	{
		dest[pos + i] = src[i];
		i++;
	}
	dest[destlen + offset] = '\0';
	return (dest);
}

char	*ft_strins_malloc(char *dest, const char *src, unsigned int pos)
{
	unsigned int	destlen;
	unsigned int	srclen;
	char			*tmp;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (ft_strdup(dest));
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	tmp = ft_memalloc(destlen + srclen + 1);
	ft_strcat(tmp, dest);
	ft_strcpy(tmp + pos, src);
	ft_strcpy(tmp + pos + srclen, dest + pos);
	return (tmp);
}
