/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:39:34 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/29 17:49:11 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_size(long n, int base)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

static char	*ft_creat_str(long n, int sign, int size, int base)
{
	char	*str;
	char	*base_str;

	base_str = "0123456789abcdef";
	str = ft_calloc(sign + size + 1, 1);
	if (!str)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	str[size--] = '\0';
	while (size >= sign)
	{
		str[size--] = base_str[n % base];
		n /= base;
	}
	return (str);
}

char	*ft_itoa_base(int n, int base, int size)
{
	long	x;
	char	*str;
	int		sign;

	sign = 0;
	x = (long)n;
	if (x < 0)
	{
		sign = 1;
		x *= -1;
	}
	if (size == 0)
		size = ft_find_size(x, base);
	str = ft_creat_str(x, sign, (size + sign), base);
	return (str);
}
