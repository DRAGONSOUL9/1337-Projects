/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:41:25 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/24 21:18:29 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>

typedef struct s_push
{
	int				num;
	int				my_index;
	int				p_current;
	int				p_target;
	int				cost;
	// int				*content;
	// char			**p_tmp;
	char			*position;
	struct s_push	*next;
	struct s_push	*previos;
}					t_push;

//moves
void				ft_swap(t_push **lst, char *str, int n_times);
void				ft_double_swap(t_push **lst1, t_push **lst2, int n_times);
void				ft_push(t_push **to_this, t_push **from_this, char *str,
						int n_times);
void				ft_rotate(t_push **lst, char *str, int n_times);
void				ft_double_rotate(t_push **lst1, t_push **lst2, int n_times);
void				ft_reverse_rotate(t_push **lst, char *str, int n_times);
void				ft_reverse_double_rotate(t_push **lst1, t_push **lst2,
						int n_times);

//linked list manupilation functions
t_push				*ft_lstnew(int num);
int					ft_lstsize(t_push *lst);
t_push				*ft_lstlast(t_push *lst);
// void				ft_lstiter(t_push *lst, void (*f)(void *));
// void				ft_lstdelone(t_push *lst, void (*del)(void *));
void				ft_lstclear(t_push **lst);
void				ft_lstadd_front(t_push **lst, t_push *new);
void				ft_lstadd_back(t_push **lst, t_push *new);
t_push				*ft_lstbeforelast(t_push *lst);

//helper functions
int					ft_find_small(t_push **a);
int					find_closest_next(t_push *a, int my_index);
int					ft_check_and_fill(int ac, const char **av, t_push **a);
void				ft_exit_ft(t_push **a, int *arr);
int					ft_issorted(t_push *a);

//sort functions
void				ft_sort_small(t_push **a, int lstsize);
void				ft_sort_three(t_push **a);
void				ft_sort_big(t_push **a, int *arr, int lstsize);

// void				ft_sort_tree(t_push **a);
// void				ft_sort_numbers(t_push **a, t_push **b, int size, int fd);
// void				ft_radix_sort(t_push **a, t_push **b, int size, int fd);

//other stuff for lst
// void				ft_lstdel(void *content);
// void				*ft_dup_wrapper(void *content);

//may need to be removed
void				ft_lstprint(t_push **, int fd);
void				ft_testing(t_push **a, int size, int fd, int position);

#endif