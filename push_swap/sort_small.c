/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:41:35 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 18:23:30 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	ft_finish(t_push **a, t_push **b, int lstsize)
{
	int	p;
	int	tmp;

	tmp = lstsize;
	while (*b)
	{
		if ((*b)->my_index == lstsize - 1)
			p = ft_find_small(a);
		else
			p = find_closest_next((*a), (*b)->my_index);
		if (p != 0 && p <= (tmp / 2))
			ft_rotate(a, "ra\n", p);
		else if (p != 0 && p > (tmp / 2))
			ft_reverse_rotate(a, "rra\n", (tmp - p));
		ft_push(a, b, "pa\n", 1);
		tmp--;
	}
}

static void	ft_sort_four(t_push **a, t_push **b, int lstsize)
{
	ft_push(b, a, "pb\n", 1);
	ft_sort_three(a);
	ft_finish(a, b, lstsize);
}
static void	ft_sort_five(t_push **a, t_push **b, int lstsize)
{
	ft_push(b, a, "pb\n", 2);
	ft_sort_three(a);
	ft_finish(a, b, lstsize);
}
static void	ft_top_small(t_push **a, int lstsize)
{
	int	p;

	p = ft_find_small(a);
	if (p == 0)
		return ;
	if (p <= (lstsize / 2))
		ft_rotate(a, "ra\n", p);
	else if (p > (lstsize / 2))
		ft_reverse_rotate(a, "rra\n", (lstsize - p));
}

void	ft_sort_small(t_push **a, int lstsize)
{
	t_push *b;

	b = NULL;
	if (ft_issorted((*a)) == 0)
		return ;
	if (lstsize == 2)
	{
		if ((*a)->num > (*a)->next->num)
			ft_swap(a, "sa\n", 1);
	}
	else if (lstsize == 3)
		ft_sort_three(a);
	else if (lstsize == 4)
		ft_sort_four(a, &b, lstsize);
	else
		ft_sort_five(a, &b, lstsize);
	ft_top_small(a, lstsize);
}