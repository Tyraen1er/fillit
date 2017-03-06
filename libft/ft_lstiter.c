/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 07:34:28 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/27 18:12:18 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		f(tmp);
		tmp = tmp2;
	}
	f(tmp);
}
