/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:02 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/17 09:31:32 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_addr(unsigned long long n, int base, char *base_str, int flag)
{
	int	printed;

	printed = 0;
	if (flag == 0)
	{
		if (n == 0)
			return (ft_putstr_fd("(nil)", 1));
		printed += ft_putstr_fd("0x", 1);
	}
	if (n / base != 0)
		printed += ft_addr((n / base), base, base_str, 1);
	printed += ft_putchar_fd(base_str[n % base], 1);
	return (printed);
}
