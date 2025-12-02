/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:41:25 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:38:07 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_push
{
	int				num;
	int				my_index;
	struct s_push	*next;
}					t_push;

// moves
void				ft_sa(t_push **a, int n_times);
void				ft_sb(t_push **b, int n_times);
void				ft_ss(t_push **a, t_push **b, int n_times);
void				ft_ra(t_push **a, int n_times);
void				ft_rb(t_push **b, int n_times);
void				ft_rr(t_push **a, t_push **b, int n_times);
void				ft_rra(t_push **a, int n_times);
void				ft_rrb(t_push **b, int n_times);
void				ft_rrr(t_push **a, t_push **b, int n_times);
void				ft_pa(t_push **a, t_push **b, int n_times);
void				ft_pb(t_push **b, t_push **a, int n_times);

// linked list manupilation functions
t_push				*ft_lstnew(int num);
int					ft_lstsize(t_push *lst);
t_push				*ft_lstlast(t_push *lst);
void				ft_lstclear(t_push **lst);
void				ft_lstadd_front(t_push **lst, t_push *new);
void				ft_lstadd_back(t_push **lst, t_push *new);
t_push				*ft_lstbeforelast(t_push *lst);

// helper functions
int					ft_check_and_fill(int ac, const char **av, t_push **a);
int					ft_issorted(t_push *a);
void				ft_exit_checker(t_push **a, t_push **b, char *str);

#endif