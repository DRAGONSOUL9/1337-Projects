/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:00:48 by oel--mou          #+#    #+#             */
/*   Updated: 2025/11/17 09:06:36 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	x;

	if (!s)
		return (NULL);
	i = 0;
	tmp = (unsigned char *)s;
	x = (unsigned char)c;
	while (tmp[i])
	{
		if (tmp[i] == x)
			return ((char *)&tmp[i]);
		i++;
	}
	if (tmp[i] == x)
		return ((char *)&tmp[i]);
	return (NULL);
}
