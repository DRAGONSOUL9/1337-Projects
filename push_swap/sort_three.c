/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:30:00 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 17:30:11 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sort_three(t_push **a)
{
	int	n1;
	int	n2;
	int	n3;

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