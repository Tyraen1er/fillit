/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitOpti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 03:15:51 by eferrand          #+#    #+#             */
/*   Updated: 2017/03/02 03:37:54 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int backtrack(t_riche *s, int sqr, p, int *n)
{
		if (p == s->nbp - 1 &&
		(ending = ft_display((pcs[p] >> n[0]), n[1], p, sqr)))
			if (s->nbp == 1)
				ft_putstr(ending);
		if (p == s->nbp - 1)
			return (1);
		if (s->nbp != 1 && !ft_opti(pcs[p] + 1, s, n[0], n[1]))
			s->p = backtracking(pcs, p + 1, sqr, s);
		if (s->p == 0 && ft_assim(s, (pcs[p] >> n[0]), n[1], 0)
				&& !ft_opti(pcs[p] + 1, s, 0, 0))
			if (++n[0] && sqr < (n[0] + n[2]) && ++n[1])
				n[0] = 0;
		return (-1);
}

int		backtracking(t_lry *pcs, int p, int sqr, t_riche *s)
{
	static char	*ending;
	int			n[4];
	int			back;

	ft_opti(&n[0], &n[1], s, pcs[p]);
	s->p = 0;	
	n[2] = (int)scn(NULL, 'x', pcs[p]);
	n[3] = (int)scn(NULL, 'y', pcs[p]);
	while (!s->p)
	{
		while ((scn(s->map, n[1], 0) & (pcs[p] >> n[0])) != 0)
			if (++n[0] && sqr < (n[0] + n[2]) && ++n[1])
				n[0] = 0;
		if (scn(s->map, n[1], 0) & (pcs[p] >> n[0]) || sqr < n[1] + n[3] ||
		sqr < n[0] + n[2])
			return (0);
		ft_assim(s, (pcs[p] >> n[0]), n[1], 1);
		if (-1 != (back = backtrack(s, sqr, p, n)))
			return (back);
	}
	if ((ending = ft_display((pcs[p] >> n[0]), n[1], p, sqr)) && !p)
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
