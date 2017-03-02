/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 01:40:01 by eferrand          #+#    #+#             */
/*   Updated: 2017/03/01 19:20:07 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		rbt(t_lry *p)
{
	if (*p)
	{
		while (!(T2 & *p))
			*p = *p << 1;
		while (!(T1 & *p))
			*p = *p << 16;
		if (!(*p ^ T1) || !(*p ^ T2) || !(*p ^ T3) || !(*p ^ T4) ||
				!(*p ^ T5) || !(*p ^ T6) || !(*p ^ T7) || !(*p ^ T8) ||
				!(*p ^ T9) || !(*p ^ T10) || !(*p ^ T11) || !(*p ^ T12) ||
				!(*p ^ T13) || !(*p ^ T14) || !(*p ^ T15) || !(*p ^ T16) ||
				!(*p ^ T17) || !(*p ^ T18) || !(*p ^ T19))
			return (0);
	}
	return (-1);
}

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

int		ft_opti(t_lry pc, t_riche *s, int *x, int *y)
{
	int		a;
	int		b;

	b = 0;
	if (pc % 10 == 1 && (b = 1))
		--pc;
	a = 0;
	while (s->opt[a] != pc && s->opt[a])
		++a;
	if (b)
	{
		s->opt[a] = pc;
		s->optx[a] = *x;
		s->opty[a] = *y;
	}
	else
	{
		*x = s->optx[a];
		*y = s->opty[a];
	}
	return (0);
}

char    *ft_display(t_lry piece, int y, int p, int sqr)
{
	static char end[183] = {0};
	int		a;
	int		b;

	a = 0;
	if (!end[0] && !(b = 0))
		while (b < sqr && ++a)
		{
			if (a == sqr + 1 && !(a = 0) && ++b)
				end[a - 1 + b * (sqr + 1)] = '\n';
			else
				end[a - 1 + b * (sqr + 1)] = '.';
		}
	end[sqr * (sqr + 1) - 1] = '\0';
	a = -1;
	b = 0;
	while (b < 4)
	{
		++a;
		if (a == sqr && ++b)
			a = -1;
		if (((t_lry)0x8000000000000000ull >> (a + b * 16)) & piece)
			end[a + b * (sqr + 1) + y * (sqr + 1)] = p + 'A';
	}
	return (end);
}
