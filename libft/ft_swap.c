/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:14:50 by araout            #+#    #+#             */
/*   Updated: 2018/12/19 17:14:51 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void **str, void **str2)
{
	void *tmp;

	tmp = *str;
	*str = *str2;
	*str2 = tmp;
}

void	ft_swap_int(int *str, int *str2)
{
	int tmp;

	tmp = *str;
	*str = *str2;
	*str2 = tmp;
}
