/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:02:42 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/17 11:10:26 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	size = (s_len - start) + 1;
	if (size > len)
		size = len + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), size);
	return (str);
}
