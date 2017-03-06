/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:19:35 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/27 18:11:26 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst && del)
	{
		tmp = *alst;
		while (tmp->next)
		{
			del(tmp->content, tmp->content_size);
			*alst = tmp->next;
			free(tmp);
			tmp = *alst;
		}
		del(tmp->content, tmp->content_size);
		free(tmp);
		*alst = NULL;
	}
}
