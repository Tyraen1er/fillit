/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 01:40:01 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/08 21:14:02 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lry	ft_scan(unsigned short *map, int y)
{
	t_lry	new;

	new = (t_lry)map[y] << 48;
	new |= (t_lry)map[y + 1] << 32 | (t_lry)map[y + 2] << 16 | map[y + 3];
	return (new);
}

int		ft_length(t_lry piece, int xy)
{
	if (xy == 'x' && (xy = 3))
		while (!(piece & (TXMAP >> xy)))
			--xy;
	if (xy == 'y' && (xy = 3))
		while (!(piece & (TYMAP >> (16 * xy))))
			--xy;
	return (xy + 1);
}

void	*ft_assim(t_riche *s, t_lry t, int y)
{
	int	a;

	a = -1;
	while (++a < 4)
		s->map[a + y] |= (unsigned short)(t >> ((3 - a) * 16));
	return (s);
}

void	*ft_dassim(t_riche *s, t_lry t, int y)
{
	int	a;

	a = -1;
	while (++a < 4)
		s->map[a + y] ^= (unsigned short)(t >> ((3 - a) * 16));
	return (s);
}
