/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:47:46 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/23 02:07:34 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	while (str[a] != c && a != 0)
		a--;
	if (str[a] == c)
		return (&((char *)str)[a]);
	return (NULL);
}
