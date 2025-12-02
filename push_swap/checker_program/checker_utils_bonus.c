/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:12:22 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:38:51 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_lstsize(t_push *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_push	*ft_lstlast(t_push *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		else
			lst = lst->next;
	}
	return (lst);
}

void	ft_exit_checker(t_push **a, t_push **b, char *str)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_issorted(t_push *a)
{
	int		small;
	t_push	*tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp)
	{
		small = tmp->num;
		if (tmp->next && (small > (tmp->next->num)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
