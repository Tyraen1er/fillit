/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:31:53 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/27 18:18:31 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;

	begin = NULL;
	while (lst != NULL)
	{
		if (begin == NULL)
		{
			begin = ft_lstnew(lst->content, lst->content_size);
			if (begin == NULL)
				return (NULL);
			begin = f(begin);
			tmp = begin;
		}
		else
		{
			tmp->next = ft_lstnew(lst->content, lst->content_size);
			if (begin == NULL)
				return (NULL);
			tmp->next = f(tmp->next);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (begin);
}
