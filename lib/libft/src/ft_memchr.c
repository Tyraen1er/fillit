/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:24:38 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 02:04:27 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			a;
	unsigned char	*snew;

	snew = (unsigned char *)str;
	a = 0;
	while (n)
	{
		if (snew[a] == (unsigned char)c)
			return (snew + a);
		a++;
		n--;
	}
	return (NULL);
}
