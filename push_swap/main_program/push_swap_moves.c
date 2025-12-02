/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:48:56 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:39:41 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_push **lst, char *str, int n_times)
{
	int		i;
	t_push	*tmp;

	if (!(*lst) || !str)
		return ;
	i = 0;
	while (i < n_times)
	{
		tmp = NULL;
		tmp = (*lst);
		(*lst) = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
		ft_putstr_fd(str, 1);
		i++;
	}
}

void	ft_push(t_push **to_this, t_push **from_this, char *str, int n_times)
{
	int		i;
	t_push	*tmp;

	if (!(*from_this) || !str)
		return ;
	i = 0;
	while (i < n_times)
	{
		tmp = NULL;
		tmp = (*from_this)->next;
		(*from_this)->next = NULL;
		ft_lstadd_front(to_this, (*from_this));
		(*from_this) = tmp;
		ft_putstr_fd(str, 1);
		i++;
	}
}

void	ft_rotate(t_push **lst, char *str, int n_times)
{
	int		i;
	t_push	*tmp;

	if (!(*lst) || !str)
		return ;
	i = 0;
	while (i < n_times)
	{
		tmp = NULL;
		tmp = (*lst)->next;
		ft_lstadd_back(lst, (*lst));
		(*lst)->next = NULL;
		(*lst) = tmp;
		ft_putstr_fd(str, 1);
		i++;
	}
}

void	ft_reverse_rotate(t_push **lst, char *str, int n_times)
{
	int		i;
	t_push	*before_last;

	if (!(*lst) || !str)
		return ;
	i = 0;
	while (i < n_times)
	{
		before_last = NULL;
		before_last = ft_lstbeforelast((*lst));
		ft_lstadd_front(lst, before_last->next);
		before_last->next = NULL;
		ft_putstr_fd(str, 1);
		i++;
	}
}
