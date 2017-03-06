/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:24:19 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 02:17:27 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *str;

	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = '\0';
	return (str);
}
