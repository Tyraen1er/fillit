/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 01:13:44 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/28 01:42:55 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_putnbr_fd2(int nb, int fd)
{
	char	c;

	if (nb > 9)
		ft_putnbr_fd2(nb / 10, fd);
	c = '0' + nb % 10;
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(fd, "-", 1);
		}
		ft_putnbr_fd2(nb, fd);
	}
}
