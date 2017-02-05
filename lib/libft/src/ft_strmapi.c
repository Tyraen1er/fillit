/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:46:03 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 03:06:14 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*res;

	if (!str && !f)
		return (NULL);
	a = 0;
	while (str[a] != '\0')
		a++;
	if (!(res = (char *)malloc(a + 1)))
		return (NULL);
	a = 0;
	while (f != NULL && str[a] != '\0')
	{
		res[a] = f(a, str[a]);
		a++;
	}
	res[a] = '\0';
	return (res);
}
