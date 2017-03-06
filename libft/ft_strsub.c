/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 02:05:03 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/27 18:07:55 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	if (str)
	{
		i = 0;
		tab = (char*)malloc(len + 1);
		if (!tab)
			return (NULL);
		while (len)
		{
			tab[i] = str[start];
			i++;
			start++;
			len--;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
