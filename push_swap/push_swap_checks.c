/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:22:00 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 18:21:19 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	ft_check_args(int ac, const char **av)
{
	int			i;
	int			i2;
	int			flag;
	const char	*str;

	i = 1;
	while (i < ac)
	{
		i2 = 0;
		flag = 0;
		str = av[i];
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

static int	ft_check_for_dups(int ac, const char **av)
{
	int	i;
	int	i2;

	i = 0;
	while (i < ac)
	{
		i2 = i + 1;
		while (i2 < ac)
		{
			if (ft_memcmp(av[i], av[i2], ft_strlen(av[i])) == 0 &&
				ft_memcmp(av[i], av[i2], ft_strlen(av[i2])) == 0)
				return (-1);
			i2++;
		}
		i++;
	}
	return (0);
}

static void	ft_fill_lst(int ac, const char **av, t_push **a)
{
	int		i;
	int		flag;
	long	x;

	i = 1;
	flag = 1;
	while (i < ac)
	{
		x = ft_atoi_new(av[i], &flag);
		if (flag < 0)
			ft_exit_ft(a, NULL);
		else
			ft_lstadd_back(a, ft_lstnew(x));
			
		i++;
	}
}

int	ft_check_and_fill(int ac, const char **av, t_push **a)
{
	if (ft_check_args(ac, av) == (-1) || ft_check_for_dups(ac, av) == (-1))
		ft_exit_ft(a, NULL);
	ft_fill_lst(ac, av, a);
	return (ft_lstsize((*a)));
}

