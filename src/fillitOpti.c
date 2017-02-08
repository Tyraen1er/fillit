/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitOpti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 03:15:51 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/07 17:10:16 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		rbt(t_lry *p)
{
	while (!(t2 & *p))
		*p = *p << 1;
	while (!(t1 & *p))
		*p = *p << 16;
	if (!(*p ^ t1) || !(*p ^ t2) || !(*p ^ t3) || !(*p ^ t4) ||
			!(*p ^ t5) || !(*p ^ t6) || !(*p ^ t7) || !(*p ^ t8) ||
			!(*p ^ t9) || !(*p ^ t10) || !(*p ^ t11) || !(*p ^ t12) ||
			!(*p ^ t13) || !(*p ^ t14) || !(*p ^ t15) || !(*p ^ t16) ||
			!(*p ^ t17) || !(*p ^ t18) || !(*p ^ t19))
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
char	*ft_fdisplay(t_lry piece, int y, int p, int square)
{
	char	end[183] = {0};
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

int		backtracking(t_lry *pieces, int p, int square, t_riche *S)
{
	static char	*ending;
	int			x;
	int			y;
	int			xm;
	int			ym;
	int			a;

	x = S->x;
	y = 0;
	a = 0;
	if (p != 0)
		x = 0;
	xm = ft_length(pieces[p], 'x');
	ym = ft_length(pieces[p], 'y');
	ft_putstr("pieces qui rentre dans le backtracking\n");
	ft_putstr(ft_fdisplay((pieces[p] >> 0), y, p, square));
	ft_putstr("\n");
	ft_putstr("situation de la map :\n");
	ft_putstr(ft_fdisplay(ft_scan(S->map, y), y, p - 1, square));
	ft_putstr("\n");
	while (a == 0)
	{
	while ((ft_scan(S->map, y) & (pieces[p] >> x)) != 0)
	{
		ft_putstr("piece rentre dans la boucle while\n");
		ft_putstr(ft_fdisplay((pieces[p] >> x), y, p, square));
		ft_putstr("\n");
		x++;
		if (square < (x + xm) && ++y)
			x = 0;
		if (square < (y + ym))
			return (0);
		ft_putstr("piece sort de la boucle while\n");
	}
	ft_putstr("sortie definitive de la piece de la boucle while\n");
	ft_putstr("\n");
	if (ft_scan(S->map, y) & (pieces[p] >> x) || square < y + ym || square < x + xm)
		return (0);
	ft_putstr("insertion de la piece dans la map:\n");
	ft_putstr(ft_fdisplay((pieces[p] >> x), y, p, square));
	ft_assim(S, (pieces[p] >> x), y);
	ft_putstr("map apres insertion:\n");
	ft_putstr(ft_fdisplay(ft_scan(S->map, y), y, p, square));
	ft_putstr("\n");
	if (p == S->nbp - 1)
	{
		ending = ft_display((pieces[p] >> x), y, p, square);
		ft_putstr("\n\n");
		return (1);
	}
	a = backtracking(pieces, p + 1, square, S);
	if (a == 0)
	{
		ft_dassim(S, (pieces[p] >> x), y);
		x++;
		S->x = x;
	}
	}
	ending = ft_display((pieces[p] >> x), y, p, square);
	ft_putstr("\nsolution finale: \n");
	ft_putstr(ending);
	return (1);
}

int		begin(t_lry *pieces, t_riche *S)
{
	int				square;
	int				a;
	int				xm;
	int				ym;
	int				p;

	xm = ft_length(pieces[0], 'x');
	ym = ft_length(pieces[0], 'y');
	a = 0;
	S->x = 0;
	S->y = 0;
	square = ft_root(2, (4 * S->nbp));
	if (square * square < (4 * S->nbp))
		++square;
	while (a == 0)
	{
		S->map = (unsigned short[16]){0};
		a = backtracking(pieces, 0, square, S);
		if (a == 0) 
		{
			S->x++;
			if (square < (S->x + xm))
			{
				S->y++;
				S->x = 0;
			}
			if (square < (S->y + ym))
			{
				S->y = 0;
				S->x = 0;
				++square;
				ft_putstr("augmente carree\n");
			}
		}
	}
	return (0);
}

int		ft_save(char *R, t_riche *S)
{
	t_lry *pc;

	pc = (t_lry[26]){0};
	while (++S->p < 26 && (S->y = -1))
	{
		while (++S->y < 4 && (S->x = -1))
			while (++S->x < 5)
			{
				if (S->x == 4 && (R[S->x + 5 * S->y + 21 * S->p] != '\n'))
					return (-1);
				else if (S->x < 4)
				{
					if (R[S->x + 5 * S->y + 21 * S->p] != '#' &&
							R[S->x + 5 * S->y + 21 * S->p] != '.')
						return (-1);
					pc[S->p] |= (t_lry)(R[S->x + 5 * S->y + 21 * S->p] == '#') <<
						(15 - S->x + (3 - S->y) * 16);
				}
			}
		if (rbt(&pc[S->p]) || (R[20 + 21 * S->p] != '\n' && R[20 + 21 * S->p]))
			return (-1);
		else if (R[20 + 21 * S->p] == '\0')
			break ;
	}
	return (begin(pc, S));
}

int		main(int argc, char **argv)
{
	char R[547];
	t_riche	S[1];
	int		x;
	int		y;

	x = 0;
	y = 0;
	S->nbp = 0;
	if (argc != 2 || (y = open(argv[1], O_RDONLY)) == -1 ||
			(x = read(y, R, 546)) == -1)
	{
		ft_putstr("Erreur Open/Read\n");
		return(0);
	}
	while (21 * S->nbp <= x)
		++S->nbp;
	R[x] = 0;
	S->p = -1;
	S->p = ft_save(R, S);
	if (S->p == -1)
		ft_putstr("S->map refusée\n");
	return (0);
}
