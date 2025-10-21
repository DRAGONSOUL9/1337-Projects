/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:55:38 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/20 16:41:29 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*tmp;
	unsigned char	x;

	tmp = NULL;
	x = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == x)
			tmp = (char *)s;
		s++;
	}
	if ((unsigned char)*s == x)
		return ((char *)s);
	return (tmp);
}
