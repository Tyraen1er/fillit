/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:59:20 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/27 23:33:18 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t a;

	a = 0;
	while (a < n && src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	while (a < n)
		dst[a++] = '\0';
	return (dst);
}
