/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:32 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/27 12:37:56 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup_size(const char *s, size_t size, int enable)
{
	size_t	i;
	char	*copy;

	if (!s)
		return (NULL);
	if (enable == 1)
		size = ft_strlen(s);
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdup_size(s1, 0, 1));
	if (!s1 && s2)
		return (ft_strdup_size(s2, 0, 1));
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

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
