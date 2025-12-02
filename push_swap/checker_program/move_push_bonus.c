/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:48:56 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 13:14:01 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_pa(t_push **a, t_push **b, int n_times)
{
	int		i;
	t_push	*tmp;

	if (!b || !a)
		return ;
	if (!(*b))
	{
		ft_putstr_fd("Error: stack 'b' is empty\n", 2);
		return ;
	}
	i = 0;
	while (i < n_times)
	{
		tmp = NULL;
		tmp = (*b)->next;
		(*b)->next = NULL;
		ft_lstadd_front(a, (*b));
		(*b) = tmp;
		i++;
	}
}

void	ft_pb(t_push **b, t_push **a, int n_times)
{
	int		i;
	t_push	*tmp;

	if (!b || !a)
		return ;
	if (!(*a))
	{
		ft_putstr_fd("Error: stack 'a' is empty\n", 2);
		return ;
	}
	i = 0;
	while (i < n_times)
	{
		tmp = NULL;
		tmp = (*a)->next;
		(*a)->next = NULL;
		ft_lstadd_front(b, (*a));
		(*a) = tmp;
		i++;
	}
}
