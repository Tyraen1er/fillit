/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 04:07:05 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 02:49:48 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_len(int nb)
{
	char	*ret;
	int		len;

	len = 1;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 9 && len++ > 0)
		nb /= 10;
	if (!(ret = (char *)malloc(++len)))
		return (NULL);
	ret[--len] = '\0';
	while (len > 0)
		ret[--len] = 'a';
	return (ret);
}

char		*ft_itoa(int nb)
{
	char	*ret;
	int		a;

	a = 0;
	if ((ret = ft_itoa_len(nb)) == NULL)
		return (NULL);
	if (nb == -2147483648)
		return (ret);
	else if (nb < 0)
	{
		nb = -nb;
		ret[a] = '-';
	}
	while (ret[a] != '\0')
		a++;
	while (nb > 9)
	{
		ret[--a] = 48 + nb % 10;
		nb /= 10;
	}
	ret[--a] = 48 + nb;
	return (ret);
}
