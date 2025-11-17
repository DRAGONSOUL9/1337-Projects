/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:39:34 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/18 15:52:53 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_size(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_creat_str(char *str, long n, int sign, int size)
{
	if (sign == 1)
		str[0] = '-';
	str[size--] = '\0';
	while (size >= sign)
	{
		str[size--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	x;
	char	*str;
	int		size;
	int		sign;

	sign = 0;
	x = (long)n;
	if (x < 0)
	{
		sign = 1;
		x *= -1;
	}
	size = ft_find_size(x);
	str = ft_calloc(sign + size + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_creat_str(str, x, sign, (size + sign)));
}
