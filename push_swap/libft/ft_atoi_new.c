/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:34:07 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 10:41:09 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sign(const char *nptr, int *sign, size_t *i)
{
	if (nptr[(*i)] == '+' || nptr[(*i)] == '-')
	{
		if (nptr[(*i)] == '-')
			(*sign) = -1;
		(*i)++;
	}
}

int	ft_atoi_new(const char *nptr, int *flag)
{
	size_t	i;
	int		sign;
	long	out;

	i = 0;
	if (!nptr)
		return ((*flag) = -1);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	ft_sign(nptr, &sign, &i);
	out = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = (out * 10) + (nptr[i] - '0');
		i++;
	}
	out *= sign;
	if ((out == 0 && nptr[0] != '0') || out > INT_MAX || out < INT_MIN)
		*flag = -1;
	return (out);
}
