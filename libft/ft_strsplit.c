/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 02:09:05 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 03:04:56 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_del_all(char **ret, size_t a, size_t i)
{
	while (a)
		free(ret[--a]);
	free(ret);
	ret = NULL;
	return (i);
}

static void			ft_attrib(char *ret, const char *str, size_t i, char c)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (str[b] != '\0' && a != i)
	{
		if (str[b] != c)
			++a;
		while (str[b] != c && str[b] != '\0')
			++b;
		while (str[b] == c)
			++b;
	}
	a = 0;
	while (str[b] == c)
		++b;
	while (str[b] != c && str[b] != '\0')
		ret[a++] = str[b++];
	ret[a] = '\0';
}

static void			ft_malloc_all(char **ret, const char *str, size_t i, char c)
{
	size_t	a;
	size_t	b;
	size_t	d;

	a = 0;
	b = 0;
	d = 0;
	while (a < i)
	{
		while (str[b] == c)
			++b;
		while (str[b] != c && str[b] != '\0')
		{
			++b;
			++d;
		}
		if (!(ret[a] = (char*)malloc(d + 1)))
			a = ft_del_all(ret, a, i);
		if (ret)
		{
			ft_attrib(ret[a], str, a, c);
			++a;
		}
	}
	ret[a] = NULL;
}

static size_t		ft_iteration(const char *str, char c)
{
	size_t	a;
	size_t	iter;

	a = 0;
	iter = 0;
	while (str[a] != '\0')
	{
		if (str[a] != c)
			++iter;
		while (str[a] != c && str[a] != '\0')
			++a;
		while (str[a] == c)
			++a;
	}
	return (iter);
}

char				**ft_strsplit(const char *str, char c)
{
	size_t	a;
	size_t	b;
	char	**ret;

	a = 0;
	b = 0;
	if (!str)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (ft_iteration(str, c) + 1))))
		return (NULL);
	ft_malloc_all(ret, str, (ft_iteration(str, c)), c);
	return (ret);
}
