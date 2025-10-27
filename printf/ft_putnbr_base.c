/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:02 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/27 15:13:30 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, int base, char *base_str)
{
	int	printed;

	printed = 0;
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
