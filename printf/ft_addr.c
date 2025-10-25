/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:02 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/24 18:26:38 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_addr(unsigned long long n, int base, char *base_str)
{
	int	printed;

	if (n == 0)
		return (ft_putstr_fd("(nil)",1));
	printed = 0;
	printed += ft_putstr_fd("0x",1);
	if (n < 0)
	{
		printed += ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n / base != 0)
		printed += ft_putnbr_base((n / base), base, base_str);
	printed += ft_putchar_fd(base_str[n % base], 1);
	return (printed);
}