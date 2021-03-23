/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_memory_unsigned_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araout   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:56:34 by araout            #+#    #+#             */
/*   Updated: 2018/12/07 23:56:35 by araout           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char		read_uchar(void *n)
{
	return (*(unsigned char*)n);
}

unsigned short		read_ushort(void *n)
{
	return (*(unsigned short*)n);
}

unsigned int		read_uint(void *n)
{
	return (*(unsigned int*)n);
}

unsigned long		read_ulong(void *n)
{
	return (*(unsigned long*)n);
}

unsigned long long	read_ullong(void *n)
{
	return (*(unsigned long long*)n);
}
