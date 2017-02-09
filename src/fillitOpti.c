/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitOpti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 03:15:51 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/09 06:11:49 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		rbt(t_lry *p)
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
	return (-1);
}

char	*ft_display(t_lry piece, int y, int p, int square)
{
	static char	end[183] = {0};
	int			a;
	int			b;

	a = 0;
	b = 0;
	if (!end[0])
		while (b < square && ++a)
		{
			if (a == square + 1 && !(a = 0) && ++b)
				end[a - 1 + b * (square + 1)] = '\n';
			else
				end[a - 1 + b * (square + 1)] = '.';
		}
	end[square * (square + 1) - 1] = '\0';
	a = -1;
	b = 0;
	while (b < 4)
	{
		++a;
		if (a == square && ++b)
			a = -1;
		if (((t_lry)0x8000000000000000ull >> (a + b * 16)) & piece)
			end[a + b * (square + 1) + y * (square + 1)] = p + 'A';
	}
	return (end);
}

int		backtracking(t_lry *pieces, int p, int square, t_riche *s)
{
	static char	*ending;
	int			x;
	int			y;
	int			xm;
	int			ym;
	int			a;

	x = s->x;
	y = 0;
	a = 0;
	if (p != 0)
		x = 0;
	xm = ft_length(pieces[p], 'x');
	ym = ft_length(pieces[p], 'y');
	while (a == 0)
	{
	while ((ft_scan(s->map, y) & (pieces[p] >> x)) != 0)
	{
		x++;
		if (square < (x + xm) && ++y)
			x = 0;
		if (square < (y + ym))
			return (0);
	}
	if (ft_scan(s->map, y) & (pieces[p] >> x) || square < y + ym || square < x + xm)
		return (0);
	ft_assim(s, (pieces[p] >> x), y);
	if (p == s->nbp - 1)
	{
		ending = ft_display((pieces[p] >> x), y, p, square);
		return (1);
	}
	a = backtracking(pieces, p + 1, square, s);
	if (a == 0)
	{
		ft_dassim(s, (pieces[p] >> x), y);
		x++;
		s->x = x;
	}
	}
	ending = ft_display((pieces[p] >> x), y, p, square);
	if (!p)
		ft_putstr(ending);
	return (1);
}

int		begin(t_lry *pieces, t_riche *s)
{
	int				square;
	int				a;
	int				xm;
	int				ym;
	int				p;

	xm = ft_length(pieces[0], 'x');
	ym = ft_length(pieces[0], 'y');
	a = 0;
	s->x = 0;
	s->y = 0;
	square = ft_root(2, (4 * s->nbp));
	if (square * square < (4 * s->nbp))
		++square;
	while (a == 0)
	{
		s->map = (unsigned short[16]){0};
		a = backtracking(pieces, 0, square, s);
		if (a == 0) 
		{
			s->x++;
			if (square < (s->x + xm))
			{
				s->y++;
				s->x = 0;
			}
			if (square < (s->y + ym))
			{
				s->y = 0;
				s->x = 0;
				++square;
			}
		}
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
					pc[s->p] |= (t_lry)(r[s->x + 5 * s->y + 21 * s->p] == '#') <<
						(15 - s->x + (3 - s->y) * 16);
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
	char r[547];
	t_riche	s[1];
	int		x;
	int		y;

	x = 0;
	y = 0;
	s->nbp = 0;
	if (argc != 2 || (y = open(argv[1], O_RDONLY)) == -1 ||
			(x = read(y, r, 546)) == -1)
	{
		ft_putstr("Erreur Open/read\n");
		return(0);
	}
	while (21 * s->nbp <= x)
		++s->nbp;
	r[x] = 0;
	s->p = -1;
	s->p = ft_save(r, s);
	if (s->p == -1)
		ft_putstr("s->map refusée\n");
	return (0);
}
