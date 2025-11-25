/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:16:49 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 11:55:59 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_lstprint(t_push **lst, int fd)
{
	t_push	*tmp;
	int		i;

	tmp = *lst;
	i = 0;
	ft_putstr_fd("\n----------------ft_lst_print-------------------\n", fd);
	while (tmp)
	{
		ft_putchar_fd('|', fd);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd("|------------->|", fd);
		ft_putnbr_fd(tmp->num, fd);
		ft_putstr_fd("|------------->|index = ", fd);
		ft_putnbr_fd(tmp->my_index, fd);
		ft_putchar_fd('|', fd);
		ft_putstr_fd("position = ", fd);
		if (tmp->position == NULL)
			ft_putendl_fd("NULL", fd);
		else
			ft_putendl_fd(tmp->position, fd);
		tmp = tmp->next;
		i++;
	}
	ft_putstr_fd("----------------ft_lst_print-------------------\n", fd);
}

void	ft_testing(t_push **a, int size, int fd, int position)
{
	ft_putendl_fd("\n-----------------ft_testing----------------", fd);
	ft_putstr_fd("size  = ", fd);
	ft_putnbr_fd(size, fd);
	ft_putstr_fd("\nposition = ", fd);
	ft_putnbr_fd(position, fd);
	ft_putchar_fd('\n', fd);
	ft_lstprint(a, fd);
	ft_putendl_fd("-----------------ft_testing----------------", fd);
}