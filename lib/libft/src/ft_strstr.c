/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:03:58 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 01:16:15 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if ((char)little[a] == '\0')
		return ((char *)big);
	while ((char)big[i] != '\0')
	{
		while ((char)big[i + a] == (char)little[a]
				&& (char)big[i + a] != '\0' && (char)little[a] != '\0')
			a++;
		if ((char)little[a] == '\0')
			return ((char*)big + i);
		a = 0;
		i++;
	}
	return (NULL);
}
