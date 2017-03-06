/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 03:16:44 by eferrand          #+#    #+#             */
/*   Updated: 2016/12/03 04:56:34 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, int len_str, int add_bytes, int reading_speed)
{
	int		a;
	char	*tmp;

	a = 0;
	if (!(tmp = (char*)malloc(len_str * reading_speed)))
		return (str);
	while (a < len_str)
	{
		tmp[a] = ((char *)str)[a];
		a++;
	}
	a = 0;
	free(str);
	str = NULL;
	if (!(str = ft_memalloc(reading_speed * (len_str + add_bytes))))
		return ((void *)tmp);
	while (a < len_str)
	{
		((char *)str)[a] = tmp[a];
		a++;
	}
	free(tmp);
	tmp = NULL;
	return (str);
}
