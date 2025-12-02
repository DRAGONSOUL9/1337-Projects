/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:59:00 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 13:15:23 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_apply_swap(t_push **a, t_push **b, char *str)
{
	if (ft_memcmp(str, "sa\n", 3) == 0)
		ft_sa(a, 1);
	else if (ft_memcmp(str, "sb\n", 3) == 0)
		ft_sb(b, 1);
	else if (ft_memcmp(str, "ss\n", 3) == 0)
		ft_ss(a, b, 1);
	else
		return ;
}

static void	ft_apply_rotate(t_push **a, t_push **b, char *str)
{
	if (ft_memcmp(str, "ra\n", 3) == 0)
		ft_ra(a, 1);
	else if (ft_memcmp(str, "rb\n", 3) == 0)
		ft_rb(b, 1);
	else if (ft_memcmp(str, "rr\n", 3) == 0)
		ft_rr(a, b, 1);
	else
		return ;
}

static void	ft_apply_reverse_rotate(t_push **a, t_push **b, char *str)
{
	if (ft_memcmp(str, "rra\n", 4) == 0)
		ft_rra(a, 1);
	else if (ft_memcmp(str, "rrb\n", 4) == 0)
		ft_rrb(b, 1);
	else if (ft_memcmp(str, "rrr\n", 4) == 0)
		ft_rrr(a, b, 1);
	else
		return ;
}

static void	apply(t_push **a, t_push **b)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_memcmp(str, "pa\n", 3) == 0)
			ft_pa(a, b, 1);
		else if (ft_memcmp(str, "pb\n", 3) == 0)
			ft_pb(b, a, 1);
		else if (ft_memcmp(str, "sa\n", 3) == 0 || ft_memcmp(str, "sb\n",
				3) == 0 || ft_memcmp(str, "ss\n", 3) == 0)
			ft_apply_swap(a, b, str);
		else if (ft_memcmp(str, "ra\n", 3) == 0 || ft_memcmp(str, "rb\n",
				3) == 0 || ft_memcmp(str, "rr\n", 3) == 0)
			ft_apply_rotate(a, b, str);
		else if (ft_memcmp(str, "rra\n", 4) == 0 || ft_memcmp(str, "rrb\n",
				4) == 0 || ft_memcmp(str, "rrr\n", 4) == 0)
			ft_apply_reverse_rotate(a, b, str);
		else
			ft_exit_checker(a, b, str);
		free(str);
	}
}

int	main(int ac, const char **av)
{
	int		success;
	t_push	*a;
	t_push	*b;

	a = NULL;
	b = NULL;
	ft_check_and_fill(ac, av, &a);
	apply(&a, &b);
	success = 1;
	if (ft_issorted(a) == 0 && (b) == NULL)
		success = 0;
	ft_lstclear(&a);
	ft_lstclear(&b);
	if (success == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
