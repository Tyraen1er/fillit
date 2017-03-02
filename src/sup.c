/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 01:40:01 by eferrand          #+#    #+#             */
/*   Updated: 2017/03/01 20:22:48 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_lry	Scan(unsigned short *map, int xy, t_lry piece)
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

void	*ft_assim(t_riche *s, t_lry t, int y, int choice)
{
	int	a;

	a = -1;
	if (choice)
		while (++a < 4)
			s->map[a + y] |= (unsigned short)(t >> ((3 - a) * 16));
	else
		while (++a < 4)
			s->map[a + y] ^= (unsigned short)(t >> ((3 - a) * 16));
	return (s);
}

int		ft_addOpti(t_lry pc, t_riche *s, int x, int y)
{
	int		a;

	a = 0;
	while (s->opt[a] != pc && s->opt[a])
		++a;
	s->opt[a] = pc;
	s->optx[a] = x;
	s->opty[a] = y;
	return (0);
}

void	ft_opti(int *n, t_riche *s, t_lry pc)
{
	int			a;

	a = 0;
	while (s->opt[a] != pc && s->opt[a])
		++a;
	n[0] = s->optx[a];
	n[1] = s->opty[a];
	s->p = 0;
	n[2] = (int)Scan(NULL, 'x', pc);
	n[3] = (int)Scan(NULL, 'y', pc);
}
