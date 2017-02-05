/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:26:09 by eferrand          #+#    #+#             */
/*   Updated: 2017/01/19 05:01:28 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *stra, const char *strb)
{
	while (*stra && *strb && *stra == *strb)
	{
		++strb;
		++stra;
	}
	return ((unsigned char)*stra - (unsigned char)*strb);
}
