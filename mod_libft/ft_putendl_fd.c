/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:09:59 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/17 09:25:56 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int printed;

	printed = 0;
	if (!s || fd < 0)
		return (-1);
	printed += ft_putstr_fd(s, fd);
	printed += ft_putchar_fd('\n', fd);
	return (printed);
}
