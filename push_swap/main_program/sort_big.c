/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:53:57 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/02 18:02:29 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_finish(t_push **a, t_push **b, int lstsize)
{
	int	p;
	int	tmp;

	tmp = lstsize;
	while (*b)
	{
		p = ft_give_p_index((*b), --lstsize);
		if (p != 0 && p <= (tmp / 2))
			ft_rotate(b, "rb\n", p);
		else if (p != 0 && p > (tmp / 2))
			ft_reverse_rotate(b, "rrb\n", (tmp - p));
		ft_push(a, b, "pa\n", 1);
		tmp--;
	}
}

static void	ft_sort_rra(t_push **a, t_push **b, int lstsize)
{
	int	i;
	int	range;

	i = 0;
	range = ft_range_decide(lstsize);
	while ((*a))
	{
		if ((*a)->my_index < i)
		{
			ft_push(b, a, "pb\n", 1);
			ft_rotate(b, "rb\n", 1);
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->my_index < range)
		{
			ft_push(b, a, "pb\n", 1);
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->next == NULL)
			ft_push(b, a, "pb\n", 1);
		else
			ft_reverse_rotate(a, "rra\n", 1);
	}
	ft_finish(a, b, lstsize);
}

static void	ft_sort_ra(t_push **a, t_push **b, int lstsize)
{
	int	i;
	int	range;

	i = 0;
	range = ft_range_decide(lstsize);
	while ((*a))
	{
		if ((*a)->my_index < i)
		{
			ft_push(b, a, "pb\n", 1);
			ft_rotate(b, "rb\n", 1);
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->my_index < range)
		{
			ft_push(b, a, "pb\n", 1);
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->next == NULL)
			ft_push(b, a, "pb\n", 1);
		else
			ft_rotate(a, "ra\n", 1);
	}
	ft_finish(a, b, lstsize);
}

void	ft_sort_big(t_push **a, t_push **b, int lstsize)
{
	int	x;

	x = move_count((*a), lstsize);
	if (x < 700)
		ft_sort_ra(a, b, lstsize);
	else
		ft_sort_rra(a, b, lstsize);
}
