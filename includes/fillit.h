/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 06:02:10 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/09 07:59:00 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# define TXMAP 0x8000800080008000ull
# define TYMAP 0xFFFF000000000000ull
# define T1 0xF000000000000000ull
# define T2 0x8000800080008000ull
# define T3 0xE000400000000000ull
# define T4 0x4000E00000000000ull
# define T5 0x8000C00080000000ull
# define T6 0x4000C00040000000ull
# define T7 0x8000E00000000000ull
# define T8 0xE000800000000000ull
# define T9 0x2000E00000000000ull
# define T10 0xE000200000000000ull
# define T11 0xC000800080000000ull
# define T12 0xC000400040000000ull
# define T13 0x80008000C0000000ull
# define T14 0x40004000C0000000ull
# define T15 0xC000600000000000ull
# define T16 0x6000C00000000000ull
# define T17 0x8000C00040000000ull
# define T18 0x4000C00080000000ull
# define T19 0xC000C00000000000ull

typedef unsigned long long	t_lry;

typedef struct		s_wag
{
	int				x;
	int				y;
	int				p;
	int				nbp;
	t_lry			*opt;
	unsigned short	*map;
}					t_riche;

t_lry				ft_scan(unsigned short *map, int y);
int					ft_length(t_lry piece, int xy);
void				*ft_assim(t_riche *structure, t_lry t, int y);
void				*ft_dassim(t_riche *structure, t_lry t, int y);

#endif
