/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:55:38 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/23 09:04:38 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*tmp;
	unsigned char	*str;
	unsigned char	x;

	i = 0;
	tmp = NULL;
	str = (unsigned char *)s;
	x = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == x)
			tmp = (char *)&str[i];
		i++;
	}
	if (str[i] == x)
		return ((char *)&str[i]);
	return (tmp);
}
