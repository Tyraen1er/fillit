/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 05:06:06 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/18 22:14:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	a;

	if (src == dst)
		return (dst);
	else if (src < dst)
	{
		a = len - 1;
		while (a + 1 > 0)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a--;
		}
	}
	else
	{
		a = 0;
		while (a < len)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a++;
		}
	}
	return (dst);
}
