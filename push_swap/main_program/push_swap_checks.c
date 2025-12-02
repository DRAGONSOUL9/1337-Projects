/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:22:00 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/02 17:59:30 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exit_args(t_push **a, char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
			free(args[i++]);
		free(args);
		args = NULL;
	}
	ft_lstclear(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	ft_check_args(char **args)
{
	int			i;
	int			i2;
	int			flag;
	const char	*str;

	i = 0;
	while (args[i])
	{
		i2 = 0;
		flag = 0;
		str = args[i];
		while (str[i2])
		{
			if ((str[0] == '-' || str[0] == '+') && flag == 0)
				flag = 1;
			else if (ft_isdigit(str[i2]) == 0)
				return (-1);
			i2++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_for_dups(t_push *a)
{
	t_push	*tmp;

	if (!a)
		return (0);
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->num == tmp->num)
				return (-1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

static void	ft_fill_lst(char **args, t_push **a)
{
	int		i;
	int		flag;
	long	x;
	t_push	*tmp;

	i = 0;
	flag = 1;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 12)
			ft_exit_args(a, args);
		x = ft_atoi_new(args[i], &flag);
		if (flag < 0)
			ft_exit_args(a, args);
		else
		{
			tmp = ft_lstnew(x);
			if (!tmp)
				ft_exit_args(a, args);
			ft_lstadd_back(a, tmp);
		}
		i++;
	}
}

int	ft_check_and_fill(int ac, const char **av, t_push **a)
{
	int		i;
	int		i2;
	char	**args;

	i = 1;
	args = NULL;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			ft_exit_args(a, args);
		if (ft_check_args(args) == (-1))
			ft_exit_args(a, args);
		ft_fill_lst(args, a);
		if (ft_check_for_dups(*a) == (-1))
			ft_exit_args(a, args);
		i2 = 0;
		while (args[i2])
			free(args[i2++]);
		free(args);
		args = NULL;
		i++;
	}
	return (ft_lstsize((*a)));
}
