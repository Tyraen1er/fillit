/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 05:45:04 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 03:10:40 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		a;
	int		b;
	char	*ret;

	a = 0;
	b = 0;
	if (!str1 || !str2)
		return (NULL);
	while (str1[a] != '\0')
		a++;
	while (str2[b] != '\0')
		b++;
	if (!(ret = (char *)malloc(a + b + 1)))
		return (NULL);
	a = -1;
	b = -1;
	while (str1[++a] != '\0')
		ret[a] = ((char *)str1)[a];
	while (str2[++b] != '\0')
		ret[a++] = ((char *)str2)[b];
	ret[a] = '\0';
	return (ret);
}
