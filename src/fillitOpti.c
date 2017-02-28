/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitOpti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 03:15:51 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/27 17:15:40 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

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

char	*ft_display(t_lry piece, int y, int p, int sqr)
{
	static char	end[183] = {0};
	int			a;
	int			b;

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

int		backtracking(t_lry *pcs, int p, int sqr, t_riche *s)
{
	static char	*ending;
	int			x;
	int			y;
	int			xm;
	int			ym;

	ft_opti(&x, &y, s, pcs[p]);
	s->p = 0;
	xm = (int)Scan(NULL, 'x', pcs[p]);
	ym = (int)Scan(NULL, 'y', pcs[p]);
	while (!s->p)
	{
		while ((Scan(s->map, y, 0) & (pcs[p] >> x)) != 0)
			if (++x && sqr < (x + xm) && ++y)
				x = 0;
			if (sqr < (y + ym))
				return (0);
		if (Scan(s->map, y, 0) & (pcs[p] >> x) || sqr < y + ym || sqr < x + xm)
			return (0);
		ft_assim(s, (pcs[p] >> x), y, 1);
		if (p == s->nbp - 1 && (ending = ft_display((pcs[p] >> x), y, p, sqr)))
			if (s->nbp == 1)
				ft_putstr(ending);
		if (p == s->nbp - 1)
			return (1);
		if (s->nbp != 1 && !ft_addOpti(pcs[p], s, x, y))
			s->p = backtracking(pcs, p + 1, sqr, s);
		if (s->p == 0 && ft_assim(s, (pcs[p] >> x), y, 0)
				&& !ft_addOpti(pcs[p], s, 0, 0))
			if (++x && sqr < (x + xm) && ++y)
				x = 0;
	}
	ending = ft_display((pcs[p] >> x), y, p, sqr);
	if (!p)
		ft_putstr(ending);
	return (1);
}

int		begin(t_lry *pcs, t_riche *s)
{
	int				sqr;
	int 			opt[4];

	s->p = 0;
	sqr = ft_root(2, (4 * s->nbp));
	if (sqr * sqr < (4 * s->nbp))
		++sqr;
	while (!s->p)
	{
		s->map = (unsigned short[16]){0};
		s->p = backtracking(pcs, 0, sqr, s);
		if (!s->p)
			++sqr;
	}
	return (0);
}

int		ft_save(char *r, t_riche *s)
{
	t_lry *pc;

	pc = (t_lry[26]){0};
	while (++s->p < 26 && (s->y = -1))
	{
		while (++s->y < 4 && (s->x = -1))
			while (++s->x < 5)
			{
				if (s->x == 4 && (r[s->x + 5 * s->y + 21 * s->p] != '\n'))
					return (-1);
				else if (s->x < 4)
				{
					if (r[s->x + 5 * s->y + 21 * s->p] != '#' &&
							r[s->x + 5 * s->y + 21 * s->p] != '.')
						return (-1);
					pc[s->p] |= (t_lry)(r[s->x + 5 * s->y + 21 * s->p] == '#')
						<< (15 - s->x + (3 - s->y) * 16);
				}
			}
		if (rbt(&pc[s->p]) || (r[20 + 21 * s->p] != '\n' && r[20 + 21 * s->p]))
			return (-1);
		else if (r[20 + 21 * s->p] == '\0')
			break ;
	}
	return (begin(pc, s));
}

int		main(int argc, char **argv)
{
	char	r[547];
	t_riche	s[1];
	int		x;
	int		y;

	x = 0;
	y = 0;
	s->nbp = 0;
	s->opt = (t_lry[19]){0};
	s->optx = (int[19]){0};
	s->opty = (int[19]){0};
	if (argc != 2 || (y = open(argv[1], O_RDONLY)) == -1 ||
			(x = read(y, r, 546)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (21 * s->nbp <= x)
		++s->nbp;
	r[x] = 0;
	s->p = -1;
	s->p = ft_save(r, s);
	if (s->p == -1)
		ft_putstr("error\n");
	return (0);
}
