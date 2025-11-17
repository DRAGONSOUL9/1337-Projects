/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:23:37 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/23 09:04:08 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_size;

	if (!little[0])
		return ((char *)big);
	i = 0;
	little_size = ft_strlen(little);
	while (big[i] && i < len && little_size <= (len - i))
	{
		if (big[i] == little[0])
			if (ft_strncmp(&big[i], little, little_size) == 0)
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
