/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:26:59 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 03:14:52 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *str, const char *str2)
{
	int a;

	a = 0;
	if (!str || !str2)
		return (1);
	while (str[a] != '\0' && str2[a] != '\0' && str[a] == str2[a])
		a++;
	if (str[a] || str2[a])
		return (0);
	else
		return (1);
}
