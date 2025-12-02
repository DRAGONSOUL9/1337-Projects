/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:30:28 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:39:35 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_lstsize(t_push *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_push	*ft_lstlast(t_push *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		else
			lst = lst->next;
	}
	return (lst);
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
