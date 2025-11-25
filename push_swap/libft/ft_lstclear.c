/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:18:22 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/20 15:29:40 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst || !del || !(*lst))
		return ;
	start = *lst;
	while (start)
	{
		tmp = start;
		start = start->next;
		ft_lstdelone(tmp, del);
	}
	(*lst) = NULL;
}
