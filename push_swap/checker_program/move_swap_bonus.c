/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:31:33 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 13:14:09 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_sa(t_push **a, int n_times)
{
	int		i;
	t_push	*tmp;

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
		tmp = NULL;
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
		i++;
	}
}

void	ft_sb(t_push **b, int n_times)
{
	int		i;
	t_push	*tmp;

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
		tmp = NULL;
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
		i++;
	}
}

void	ft_ss(t_push **a, t_push **b, int n_times)
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
		ft_sa(a, 1);
		ft_sb(b, 1);
		i++;
	}
}
