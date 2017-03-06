/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:25:34 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/18 04:38:56 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *tab, int c, size_t n)
{
	unsigned char	a;
	char			*str;

	a = c;
	c = n;
	str = (char *)tab;
	while (--c >= 0)
		str[c] = a;
	return (tab);
}
