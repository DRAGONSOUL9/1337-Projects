/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:31:12 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/19 11:35:09 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	x;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	x = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
