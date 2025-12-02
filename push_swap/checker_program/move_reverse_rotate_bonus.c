/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:32:02 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 13:14:04 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_rra(t_push **a, int n_times)
{
	int		i;
	t_push	*before_last;

	if (!a)
		return ;
	if (!(*a) || (*a)->next == NULL)
	{
		if (!(*a))
			ft_putstr_fd("Error: Stack 'a' is empty.\n", 2);
		else
			ft_putstr_fd("Error: Stack 'a' has one number.\n", 2);
		return ;
	}
	i = 0;
	while (i < n_times)
	{
		before_last = NULL;
		before_last = ft_lstbeforelast((*a));
		ft_lstadd_front(a, before_last->next);
		before_last->next = NULL;
		i++;
	}
}

void	ft_rrb(t_push **b, int n_times)
{
	int		i;
	t_push	*before_last;

	if (!b)
		return ;
	if (!(*b) || (*b)->next == NULL)
	{
		if (!(*b))
			ft_putstr_fd("Error: Stack 'b' is empty.\n", 2);
		else
			ft_putstr_fd("Error: Stack 'b' has one number.\n", 2);
		return ;
	}
	i = 0;
	while (i < n_times)
	{
		before_last = NULL;
		before_last = ft_lstbeforelast((*b));
		ft_lstadd_front(b, before_last->next);
		before_last->next = NULL;
		i++;
	}
}

void	ft_rrr(t_push **a, t_push **b, int n_times)
{
	int	i;

	if (!b || !a)
		return ;
	if (!(*a) || !(*b) || (*a)->next == NULL || (*b)->next == NULL)
	{
		if (!(*a) || !(*b))
			ft_putstr_fd("Error: One/Both stack(s) is empty \n", 2);
		else
			ft_putstr_fd("Error: One/Both stack(s) has one number\n", 2);
		return ;
	}
	i = 0;
	while (i < n_times)
	{
		ft_rra(a, 1);
		ft_rrb(b, 1);
		i++;
	}
}
