/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel--mou <oel--mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:49:15 by oel--mou          #+#    #+#             */
/*   Updated: 2025/10/27 12:36:42 by oel--mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_final_size(char *left)
{
	size_t	i;

	i = 0;
	if (!left)
		return (0);
	while (left[i] && left[i] != '\n')
		i++;
	if (left[i] == '\n')
		i++;
	return (i);
}

static char	*ft_fill_left(int fd, char **left)
{
	char	*buff;
	char	*tmp;
	ssize_t	r_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	r_bytes = 1;
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buff, BUFFER_SIZE);
		if (r_bytes <= 0)
			break ;
		buff[r_bytes] = '\0';
		tmp = ft_strjoin((*left), buff);
		free((*left));
		*left = tmp;
		if (!&(*left) || ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (*left);
}

char	*get_next_line(int fd)
{
	char			*tmp;
	char			*result;
	char			**left;
	static char		*arr[1024];
	size_t			final_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = &arr[fd];
	if (!ft_strchr((*left), '\n'))
		ft_fill_left(fd, &(*left));
	final_size = ft_final_size((*left));
	if (final_size > 0)
	{
		result = ft_strdup_size((*left), final_size, 0);
		tmp = ft_strdup_size(&(*left)[final_size], 0, 1);
		free((*left));
		(*left) = tmp;
		return (result);
	}
	free((*left));
	return (NULL);
}
