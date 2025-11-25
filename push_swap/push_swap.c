/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:44:13 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/25 09:12:57 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_arr(int lstsize, int *arr)
{
	int	i;

	i = 0;
	while (i < lstsize)
	{
		if (i != 0)
		ft_printf("->");
		ft_printf("%d", arr[i]);
		i++;
	}
}

int	*ft_create_sorted_array(int ac, const char **av, int lstsize)
{
	int	i;
	int	i2;
	int	tmp;
	int	*arr;

	arr = calloc(lstsize, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	i2 = 1;
	while (i2 < ac)
	{
		arr[i] = ft_atoi(av[i2]);
		i++;
		i2++;
	}
	i = 0;
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
	return (arr);
}

void	give_index(t_push *a, int listsize, int *arr)
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

int	main(int ac, const char **av)
{
	int fd;
	int lstsize;
	int *arr;
	t_push *a;
	t_push *b;
	// char **parts;

	a = NULL;
	b = NULL;
	arr = NULL;

	fd = open("output.txt", O_RDWR | O_TRUNC);
	// if (ac == 2)
	// {
	//     parts = ft_split((const char *)av[1], ' ');
	//     ft_check_args(ac, (const char **)parts, &a);
	// }
	// else
	lstsize = ft_check_and_fill(ac, av, &a);
	if (ac < 3)
		ft_exit_ft(&a, arr);
	arr = ft_create_sorted_array(ac, av, lstsize);
	if (!arr)
		ft_exit_ft(&a, arr);
	give_index(a, ac, arr);
	// print_arr(lstsize, sorted_arr);
	// ft_printf("ac == %d || lstsize == %d", ac, lstsize);
	ft_lstprint(&a, fd);
	if (lstsize <= 5)
		ft_sort_small(&a, lstsize);
	else
		ft_sort_big(&a, arr,lstsize);

	// ft_sort_numbers(&a, &b, ft_lstsize(a), fd);
	// ft_radix_sort(&a, &b, ft_lstsize(a), fd);
	// ft_putstr_fd("\nresult", fd);
	ft_lstprint(&a, fd);

	ft_lstclear(&a);
	free(arr);

	return (0);
}