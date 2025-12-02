/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:26:01 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/02 18:28:06 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_n_finish(t_push **a, t_push **b, int lstsize, int *n)
{
	int	p;
	int	tmp;

	tmp = lstsize;
	while (*b)
	{
		p = ft_give_p_index((*b), --lstsize);
		if (p != 0 && p <= (tmp / 2))
		{
			ft_rotate(b, "", p);
			(*n) += p;
		}
		else if (p != 0 && p > (tmp / 2))
		{
			ft_reverse_rotate(b, "", (tmp - p));
			(*n) += (tmp - p);
		}
		ft_push(a, b, "", 1);
		(*n) += 1;
		tmp--;
	}
}

static void	ft_n_sort_big(t_push **a, t_push **b, int lstsize, int *n)
{
	int	i;
	int	range;

	i = 0;
	range = ft_range_decide(lstsize);
	while ((*a))
	{
		if ((*a)->my_index < i)
		{
			ft_push(b, a, "", 1);
			ft_rotate(b, "", 1);
			(*n) += 2;
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->my_index < range)
		{
			ft_push(b, a, "", 1);
			(*n) += 1;
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->next == NULL)
		{
			ft_push(b, a, "", 1);
			(*n) += 1;
		}
		else
		{
			ft_rotate(a, "", 1);
			(*n) += 1;
		}
	}
	ft_n_finish(a, b, lstsize, n);
}

int	move_count(t_push *a, int lstsize)
{
	t_push *a_copy;
	t_push *b_copy;
	int n;

	a_copy = NULL;
	b_copy = NULL;
	n = 0;
	ft_lstcopy(a, &a_copy);
	ft_n_sort_big(&a_copy, &b_copy, lstsize, &n);
	ft_lstclear(&a_copy);
	ft_lstclear(&b_copy);
	return (n);
}