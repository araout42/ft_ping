/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:18:38 by araout            #+#    #+#             */
/*   Updated: 2018/11/06 19:18:39 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*copy_word(const char *src, char *limit)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] && ft_cfind(limit, src[i]) == -1)
		i++;
	output = (char*)ft_strnew(i);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (src[i] && ft_cfind(limit, src[i]) == -1)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

static int		count_words(const char *str, char *limit)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_cfind(limit, str[i]) == -1)
		{
			count++;
			while (str[i] && ft_cfind(limit, str[i]) == -1)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char		**free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char *limit)
{
	char	**output;
	int		i;
	int		x;

	if (s == 0 || !(output = (char**)ft_memalloc(sizeof(char*)
		* count_words(s, limit))))
		return (NULL);
	x = 0;
	i = 0;
	while (s[i])
	{
		if (ft_cfind(limit, s[i]) == -1)
		{
			if ((output[x] = copy_word(s + i, limit)) == NULL)
				return (free_tab(output, x));
			while (s[i] && ft_cfind(limit, s[i]) == -1)
				i++;
			x++;
		}
		else
			i++;
	}
	output[x] = 0;
	return (output);
}
