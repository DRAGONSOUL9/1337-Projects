/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:20:50 by oel--mou          #+#    #+#             */
/*   Updated: 2025/12/01 14:47:27 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_arr(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	words;

	if (c == '\0')
		return (1);
	i = 0;
	words = 0;
	if (s[i] && s[i] != c)
		words++;
	while (s[i])
	{
		if (i != 0 && s[i - 1] == c && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static char	*ft_fill_word(char const *s, char c, size_t *i)
{
	char	*tmp;
	size_t	word_size;

	word_size = 0;
	while (s[word_size] && s[word_size] != c)
		word_size++;
	tmp = malloc(word_size + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, word_size + 1);
	(*i) += word_size;
	return (tmp);
}

static char	**ft_fill_arr(char const *s, char c, char **result)
{
	size_t	i;
	size_t	arr_i;

	i = 0;
	arr_i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
		{
			result[arr_i] = ft_fill_word(&s[i], c, &i);
			if (!result[arr_i])
			{
				ft_clear_arr(result, arr_i);
				free(result);
				return (NULL);
			}
			arr_i++;
		}
		else
			i++;
	}
	result[arr_i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	words = 0;
	words = ft_word_count(s, c);
	if (words == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	result = ft_fill_arr(s, c, result);
	return (result);
}
