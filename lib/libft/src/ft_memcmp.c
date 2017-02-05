/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:24:46 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 02:54:58 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t a;

	a = 0;
	if (!str1 || !str2)
		return (0);
	while (((unsigned char *)str1)[a] == ((unsigned char *)str2)[a] &&
			a + 1 < n)
		a++;
	if (((unsigned char *)str1)[a] != ((unsigned char *)str2)[a] && n)
		return (((unsigned char *)str1)[a] - ((unsigned char *)str2)[a]);
	return (0);
}
