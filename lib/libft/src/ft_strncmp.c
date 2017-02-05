/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:01:34 by eferrand          #+#    #+#             */
/*   Updated: 2017/01/19 04:54:43 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *stra, const char *strb, size_t n)
{
	if (!n)
		return (0);
	while (*stra && *stra == *strb && --n)
	{
		++stra;
		++strb;
	}
	return ((unsigned char)*stra - (unsigned char)*strb);
}
