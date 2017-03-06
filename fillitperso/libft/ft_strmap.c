/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:45:56 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 03:00:40 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		a;
	char	*res;

	if (!str)
		return (NULL);
	a = 0;
	while (str[a] != '\0')
		a++;
	if (!(res = malloc(a + 1)))
		return (NULL);
	a = 0;
	while (f != NULL && str[a] != '\0')
	{
		res[a] = f(str[a]);
		a++;
	}
	res[a] = '\0';
	return (res);
}
