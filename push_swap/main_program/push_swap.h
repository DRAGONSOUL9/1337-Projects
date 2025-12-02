/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:41:25 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/02 17:57:10 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_push
{
	int				num;
	int				my_index;
	struct s_push	*next;
}					t_push;

// moves
void				ft_swap(t_push **lst, char *str, int n_times);
void				ft_push(t_push **to_this, t_push **from_this, char *str,
						int n_times);
void				ft_rotate(t_push **lst, char *str, int n_times);
void				ft_reverse_rotate(t_push **lst, char *str, int n_times);

// linked list manupilation functions
t_push				*ft_lstnew(int num);
int					ft_lstsize(t_push *lst);
t_push				*ft_lstlast(t_push *lst);
void				ft_lstclear(t_push **lst);
void				ft_lstadd_front(t_push **lst, t_push *new);
void				ft_lstadd_back(t_push **lst, t_push *new);
t_push				*ft_lstbeforelast(t_push *lst);
void				ft_lstcopy(t_push *src, t_push **dest);

// helper functions
int					ft_find_small(t_push **a);
int					find_closest_next(t_push *a, int my_index);
int					ft_check_and_fill(int ac, const char **av, t_push **a);
void				ft_exit_ft(t_push **a, int *arr);
int					ft_issorted(t_push *a);

int					ft_range_decide(int lstsize);
void				ft_advance_range(int *i, int *range, int lstsize);
int					ft_give_p_index(t_push *lst, int index);
int					move_count(t_push *a, int lstsize);

// sort functions
void				ft_sort_small(t_push **a, int lstsize);
void				ft_sort_three(t_push **a);
void				ft_sort_big(t_push **a, t_push **b, int lstsize);
#endif