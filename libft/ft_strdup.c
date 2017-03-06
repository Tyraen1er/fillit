/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:22:32 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/22 23:52:54 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		a;
	char	*dup;

	a = 0;
	while (str[a] != '\0')
		a++;
	dup = (char *)malloc(sizeof(char) * (a + 1));
	if (dup == NULL)
		return (NULL);
	a = 0;
	while (str[a] != '\0')
	{
		dup[a] = str[a];
		a++;
	}
	dup[a] = '\0';
	return (dup);
}
