/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:30:28 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 11:54:52 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_push	*ft_lstnew(int num)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
		return (NULL);
	new->num = num;
	new->my_index = 0;
	new->p_current = 0;
	new->p_target = 0;
	new->cost = 0;
	new->next = NULL;
	new->previos = NULL;
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
	t_push *tmp;
	
	if (!lst || !new)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		new->previos = tmp;
	}
}
// void	ft_lstiter(t_push *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }
// void	ft_lstdelone(t_push *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// 	lst = NULL;
// }
// void	ft_lstclear(t_push **lst, void (*del)(void *))
// {
// 	t_push	*tmp;
// 	t_push	*start;

// 	if (!lst || !del || !(*lst))
// 		return ;
// 	start = *lst;
// 	while (start)
// 	{
// 		tmp = start;
// 		start = start->next;
// 		ft_lstdelone(tmp, del);
// 	}
// 	(*lst) = NULL;
// }

t_push	*ft_lstbeforelast(t_push *lst)
{
	t_push *start;
	t_push *after;

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