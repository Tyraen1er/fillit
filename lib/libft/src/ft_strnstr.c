/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:02:54 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/28 00:08:11 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *src, const char *str, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (str[a] == '\0')
		return ((char *)src);
	while (src[i] != '\0' && i < n)
	{
		while (src[i + a] == str[a]
				&& src[i + a] != '\0' && str[a] != '\0' && (i + a) < n)
			a++;
		if (str[a] == '\0')
			return ((char *)src + i);
		i++;
		a = 0;
	}
	return (NULL);
}
