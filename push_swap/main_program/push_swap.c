/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:44:13 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:39:46 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_arr(int *arr, int lstsize)
{
	int	i;
	int	i2;
	int	tmp;

	i = 0;
	i2 = 0;
	while (i < lstsize)
	{
		i2 = i + 1;
		while (i2 < lstsize)
		{
			if (arr[i] > arr[i2])
			{
				tmp = arr[i];
				arr[i] = arr[i2];
				arr[i2] = tmp;
			}
			i2++;
		}
		i++;
	}
}

static int	*ft_create_sorted_array(t_push *a, int lstsize)
{
	int	i;
	int	*arr;

	arr = calloc(lstsize, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i] = a->num;
		a = a->next;
		i++;
	}
	ft_sort_arr(arr, lstsize);
	return (arr);
}

static void	give_index(t_push *a, int listsize, int *arr)
{
	int		i;
	t_push	*tmp;

	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < listsize)
		{
			if (arr[i] == tmp->num)
			{
				tmp->my_index = i;
				break ;
			}
			else
				i++;
		}
		tmp = tmp->next;
	}
}

static void	ft_push_swap(t_push **a, int lstsize)
{
	int		*arr;
	t_push	*b;

	arr = NULL;
	b = NULL;
	arr = ft_create_sorted_array((*a), lstsize);
	if (!arr)
		ft_exit_ft(a, arr);
	give_index((*a), lstsize, arr);
	free(arr);
	if (ft_issorted(*a) == 0)
		return ;
	if (lstsize <= 5)
		ft_sort_small(a, lstsize);
	else
		ft_sort_big(a, &b, lstsize);
	ft_lstclear(&b);
}

int	main(int ac, const char **av)
{
	int		lstsize;
	t_push	*a;

	a = NULL;
	if (ac < 2)
		return (0);
	lstsize = ft_check_and_fill(ac, av, &a);
	ft_push_swap(&a, lstsize);
	ft_lstclear(&a);
	return (0);
}
