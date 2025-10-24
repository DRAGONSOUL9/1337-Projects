/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:12:44 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/24 10:45:46 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t printed;

	printed = 0;
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		printed += ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		printed += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if ((n / 10) != 0)
		printed += ft_putnbr_fd((n / 10), fd);
	printed += ft_putchar_fd(((n % 10) + '0'), fd);
	return (printed);
}
