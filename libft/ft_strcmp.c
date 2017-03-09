/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:08:25 by lmazzi            #+#    #+#             */
/*   Updated: 2016/11/19 18:03:40 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (((unsigned char)s1[i] != '\0')
			&& ((unsigned char)s1[i] == (unsigned char)s2[i]))
	{
		s1 = s1 + 1;
		s2 = s2 + 1;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
