/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 06:02:10 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/07 17:00:49 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

# define txmap 0x8000800080008000ull

# define tymap 0xFFFF000000000000ull

# define t1 0xF000000000000000ull		/****/

# define t2 0x8000800080008000ull		/*
										 *
										 *
										 */

# define t3 0xE000400000000000ull		/***
										  */

# define t4 0x4000E00000000000ull		/*
										***/

# define t5 0x8000C00080000000ull		/*
										 **
										 */

# define t6 0x4000C00040000000ull		/*
										**
										 */

# define t7 0x8000E00000000000ull		/*
										 ***/

# define t8 0xE000800000000000ull		/***
										 */

# define t9 0x2000E00000000000ull		/*
									   ***/

# define t10 0xE000200000000000ull		/***
										   */

# define t11 0xC000800080000000ull		/**
										 *
										 */

# define t12 0xC000400040000000ull		/**
										  *
										  */

# define t13 0x80008000C000000ull		/*
										 *
										 **/

# define t14 0x40004000C000000ull		/*
										 *
										**/

# define t15 0xC000600000000000ull		/**
										  **/

# define t16 0x6000C00000000000ull		/**
										**/

# define t17 0x8000C00040000000ull		/*
										 **
										  */

# define t18 0x4000C00080000000ull		/*
										**
										*/

# define t19 0xC000C00000000000ull		/**
										 **/
typedef unsigned long long	t_lry;

typedef struct		s_wag
{
	int				x;
	int				y;
	int				p;
	int				nbp;
	unsigned short	*map;
}					t_riche;

t_lry	ft_scan(unsigned short *map, int y);
int		ft_length(t_lry piece, int xy);
void	*ft_assim(t_riche *S, t_lry t, int y);
void	*ft_dassim(t_riche *S, t_lry t, int y);

#endif
