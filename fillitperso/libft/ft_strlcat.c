/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:18:38 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/27 23:25:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		a;
	size_t		b;
	size_t		c;

	a = 0;
	b = 0;
	while (a < n && dst[a] != '\0')
		a++;
	if (a == n)
		return (a + ft_strlen((char *)src));
	c = a;
	while (a < n - 1 && src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	while (src[b] != '\0')
		b++;
	dst[a] = '\0';
	return (c + b);
}
