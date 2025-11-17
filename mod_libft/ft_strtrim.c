/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:57 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/20 17:34:33 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	i = 0;
	while (i < s1_len && ft_strchr(set, s1[i]))
		i++;
	while (s1_len > i && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	return (ft_substr(s1, i, (s1_len - i)));
}
