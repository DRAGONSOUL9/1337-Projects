/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:12:22 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 18:21:43 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_exit_ft(t_push **a, int *arr)
{
	ft_lstclear(a);
	free(arr);
	ft_printf("Error\n");
	exit(1);
}

int     ft_issorted(t_push *a)
{
	int	small;
	t_push *tmp;
	

	if (!a)
		return (1);
	tmp = a;
    while(tmp)
	{
		small = tmp->num;
		if (tmp->next && (small > (tmp->next->num)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_find_small(t_push **a)
{
	int		i;
	int		position;
	int		tmp;
	int		x;
	t_push	*scan;

	i = 0;
	scan = *a;
	position = -1;
	tmp = scan->my_index;
	while (scan)
	{
		x = scan->my_index;
		if (x < tmp)
		{
			tmp = x;
			position = i;
		}
		scan = scan->next;
		i++;
	}
	return (position);
}

int	find_closest_next(t_push *a, int my_index)
{
	int		i;
	int		last;
	int		p;
	t_push	*tmp;

	tmp = a;
	i = 0;
	p = 0;
	last = 2147483647;
	while (tmp)
	{
		if (tmp->my_index > my_index && tmp->my_index < last)
		{
			p = i;
			last = tmp->my_index;
		}
		i++;
		tmp = tmp->next;
	}
	return (p);
}


// void	ft_lstdel(void *content)
// {
// 	free(content);
// 	content = NULL;
// }

// void	*ft_dup_wrapper(void *content)
// {
// 	return (ft_strdup((const char *)content));
// }

// int	find_closest_pre(t_push *a, int my_index)
// {
// 	int		i;
// 	int		last;
// 	int		p;
// 	t_push	*tmp;
// 	tmp = a;
// 	i = 0;
// 	p = 0;
// 	last = 0;
// 	while (tmp)
// 	{
// 		if (tmp->my_index < my_index && tmp->my_index > last)
// 		{
// 			p = i;
// 			last = tmp->my_index;
// 		}
// 		i++;
// 		tmp = tmp->next;
// 		// ft_printf("%d\n", p);
// 	}
// 	return (p);
// }