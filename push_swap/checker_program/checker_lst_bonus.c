/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_lst_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:30:28 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:38:48 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_push	*ft_lstnew(int num)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
		return (NULL);
	new->num = num;
	new->my_index = 0;
	new->next = NULL;
	return (new);
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

void	ft_lstadd_front(t_push **lst, t_push *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_push **lst, t_push *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
		ft_lstlast(*lst)->next = new;
}

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
