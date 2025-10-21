/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:23:37 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/17 11:09:02 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	s2_size;

	if (!little[0])
		return ((char *)big);
	i = 0;
	s2_size = ft_strlen(little);
	while (big[i] && i < len && s2_size <= (len - i))
	{
		if (big[i] == little[0])
			if (ft_strncmp(&big[i], little, (s2_size)) == 0)
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
