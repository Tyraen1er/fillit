/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 04:41:44 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/28 00:23:17 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countend(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i--;
	return (i);
}

char			*ft_strtrim(char const *str)
{
	int		i;
	char	*tab;
	int		start;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (ft_strnew(1));
	tab = (char*)malloc(sizeof(char) * (countend(str) - i + 2));
	if (!tab)
		return (NULL);
	start = i;
	i = 0;
	while (start != countend(str))
	{
		tab[i] = str[start];
		i++;
		start++;
	}
	tab[i] = str[start];
	tab[i + 1] = '\0';
	return (tab);
}
