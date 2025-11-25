/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:53:57 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/25 09:35:27 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_range_deicde(int lstsize)
{
	if (lstsize <= 100)
		return (lstsize / 10);
	else if (lstsize <= 500)
		return (lstsize / 15);
	else
		return (lstsize / 20);
}

void	ft_advance_range(int *i, int *range, int lstsize)
{
	if ((*i) < lstsize)
		(*i)++;
	if ((*range) < lstsize)
		(*range)++;
}

int	ft_give_p_index(t_push *lst, int index)
{
	int		i;
	t_push	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->my_index == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

// void    ft_finish_big(t_push **a, t_push **b, int lstsize)
// {
//     int p;

//     p = 0;
//     while((*b))
//     {
//         p = ft_give_p_index((*b), --lstsize);
//         if (p != 0 && p <= (tmp / 2))
// 			ft_rotate(a, "ra\n", p);
// 		else if (p != 0 && p > (tmp / 2))
// 			ft_reverse_rotate(a, "rra\n", (tmp - p));
// 		ft_push(a, b, "pa\n", 1);
//     }
// }

static void	ft_finish(t_push **a, t_push **b, int lstsize)
{
	// int	i;

	int	p;
	int	tmp;
	tmp = lstsize;
	while (*b)
	{
		// if ((*b)->my_index == lstsize - 1)
		// 	p = ft_find_small(a);
		// else
		// 	p = ft_give_p_index((*b), --lstsize);
		// p = find_closest_next((*a), (*b)->my_index);
		p = ft_give_p_index((*b), --lstsize);
		if (p != 0 && p <= (tmp / 2))
			ft_rotate(b, "rb\n", p);
		else if (p != 0 && p > (tmp / 2))
			ft_reverse_rotate(b, "rrb\n", (tmp - p));
		// lstsize--;
		// i = 0;
		// while ((*b)->my_index != lstsize && i <= lstsize)
		// {
		// 	// ft_printf("myindex == %d | lstsize == %d\n",(*b)->my_index,
		// 	// lstsize);
		// 	ft_rotate(b, "rb\n", 1);
		// 	i++;
		// }
		ft_push(a, b, "pa\n", 1);
		// ft_lstprint(a, 1);
		tmp--;
	}
}

void	ft_sort_big(t_push **a, int *arr, int lstsize)
{
	int i;
	int range;
	t_push *b;

	b = NULL;
	// ft_lstprint(a, 1);

	(void)arr;
	range = ft_range_deicde(lstsize);
	while ((*a))
	{
		if ((*a)->my_index < i)
		{
			ft_push(&b, a, "pb\n", 1);
			ft_rotate(&b, "rb\n", 1);
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->my_index < range)
		{
			ft_push(&b, a, "pb\n", 1);
			ft_advance_range(&i, &range, lstsize);
		}
		else if ((*a)->next == NULL)
			ft_push(&b, a, "pb\n", 1);
		else
			ft_rotate(a, "ra\n", 1);
	}
	// ft_printf("lst b \\/\\/\\/\\/\\/\\/\\/\\/");
	// ft_lstprint(&b, 1);
	ft_finish(a, &b, lstsize);
	// ft_lstprint(a, 1);
}