/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 01:40:01 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/27 17:15:43 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_lry	scn(unsigned short *map, int xy, t_lry piece)
{
	t_lry	new;

	if (!piece)
	{
	new = (t_lry)map[xy] << 48;
	new |= (t_lry)map[xy + 1] << 32 | (t_lry)map[xy + 2] << 16 | map[xy + 3];
	return (new);
	}
	else
	{
	if (xy == 'x' && (xy = 3))
		while (!(piece & (TXMAP >> xy)))
			--xy;
	if (xy == 'y' && (xy = 3))
		while (!(piece & (TYMAP >> (16 * xy))))
			--xy;
	return (xy + 1);
	}
}

void	*ft_assim(t_riche *s, t_lry pc, int y, int choice)
{
	int	a;

	a = -1;
	if (choice)
		while (++a < 4)
			s->map[a + y] |= (unsigned short)(pc >> ((3 - a) * 16));
	else
		while (++a < 4)
			s->map[a + y] ^= (unsigned short)(pc >> ((3 - a) * 16));
	return (s);
}

int		ft_addopti(t_lry pc, t_riche *s, int *x, int *y)
{
	int		a;

	a = 0;
	while (s->opt[a] != pc && s->opt[a])
		++a;
	s->opt[a] = pc;
	s->optx[a] = *x;
	s->opty[a] = *y;
	return (0);
}

void	ft_opti(int *x, int *y, t_riche *s, t_lry pc)
{
	int			a;

	a = 0;
	while (s->opt[a] != pc && s->opt[a])
		++a;
	*x = s->optx[a];
	*y = s->opty[a];
}
