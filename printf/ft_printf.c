/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:12:31 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/24 11:53:23 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_print_type(char c, va_list args)
{
	int		size;
	char	*base_str;

	base_str = "0123456789abcdef";
	size = 0;
	if (c == 'c')
		size = (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		size = (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		size += (ft_addr((long long)va_arg(args, void *), 16, base_str));
	else if (c == 'd' || c == 'i')
		size = (ft_putnbr_base((long long)va_arg(args, int), 10, base_str));
	else if (c == 'u')
		size = (ft_putnbr_base((long long)va_arg(args, unsigned int), 10,
					base_str));
	else if (c == 'x')
		size = (ft_putnbr_base((long long)va_arg(args, unsigned int), 16,
					base_str));
	else if (c == 'X')
		size = (ft_putnbr_base((long long)va_arg(args, unsigned int), 16,
					"0123456789ABCDEF"));
	else if (c == '%')
		size = (ft_putchar_fd('%', 1));
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int size;
	va_list args;

	if (!str)
		return (-1);
	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_print_type(str[++i], args);
			i++;
		}
		else
		{
			size += ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (size);
}