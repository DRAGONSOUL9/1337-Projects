/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:23:54 by oussama           #+#    #+#             */
/*   Updated: 2025/12/02 18:23:21 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_lstbeforelast(t_push *lst)
{
	t_push	*start;
	t_push	*after;

	if (!lst)
		return (NULL);
	while (lst)
	{
		start = lst;
		after = lst->next;
		if (after->next == NULL)
			break ;
		else
			lst = lst->next;
	}
	return (start);
}

void	ft_lstclear(t_push **lst)
{
	t_push	*tmp;
	t_push	*start;

	if (!lst || !(*lst))
		return ;
	start = *lst;
	while (start)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
	(*lst) = NULL;
}

void	ft_lstcopy(t_push *src, t_push **dest)
{
	t_push *tmp;
	
	while(src)
	{
		tmp = ft_lstnew(src->num);
		if (!tmp)
			return;
		tmp->my_index = src->my_index;
		ft_lstadd_back(dest, tmp);
		src = src->next;
	}
}