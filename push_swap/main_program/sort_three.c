/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:30:00 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/02 17:55:15 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_range_decide(int lstsize)
{
	if (lstsize <= 20)
		return (lstsize / 2);
	else if (lstsize <= 100)
		return (lstsize / 7);
	else
		return (lstsize / 15);
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

void	ft_sort_three(t_push **a)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = (*a)->num;
	n2 = (*a)->next->num;
	n3 = (*a)->next->next->num;
	if (n1 < n2 && n2 < n3 && n3 > n1)
		return ;
	else if (n1 > n2 && n2 < n3 && n3 > n1)
		ft_swap(a, "sa\n", 1);
	else if (n1 > n2 && n2 > n3 && n3 < n1)
	{
		ft_swap(a, "sa\n", 1);
		ft_reverse_rotate(a, "rra\n", 1);
	}
	else if (n1 > n2 && n2 < n3 && n3 < n1)
		ft_rotate(a, "ra\n", 1);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		ft_swap(a, "sa\n", 1);
		ft_rotate(a, "ra\n", 1);
	}
	else if (n1 < n2 && n2 > n3 && n3 < n1)
		ft_reverse_rotate(a, "rra\n", 1);
}
