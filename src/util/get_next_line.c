/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 13:51:20 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_free(char **ptr, t_gnl *gnl)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (gnl)
	{
		free(gnl->buffer);
		free(gnl->line);
		gnl->buffer = NULL;
		gnl->line = NULL;
	}
	return (NULL);
}

void	append(t_gnl *gnl)
{
	char	*tmp;

	if (gnl->line == NULL)
		gnl->line = ft_strdup(gnl->chunk);
	else
	{
		tmp = gnl->line;
		gnl->line = ft_strjoin(gnl->line, gnl->chunk);
		ft_free(&tmp, NULL);
	}
	ft_free(&gnl->chunk, NULL);
}

void	split(char **chunk_saved, t_gnl *gnl)
{
	char	*line_break;
	char	*tmp;
	char	*to_split;
	size_t	len;

	tmp = NULL;
	to_split = gnl->buffer;
	if (*chunk_saved)
		to_split = *chunk_saved;
	line_break = ft_strchr(to_split, '\n');
	if (line_break)
	{
		gnl->is_reading = 0;
		len = (line_break - to_split) + 1;
		gnl->chunk = ft_substr(to_split, 0, len);
		tmp = ft_substr(to_split, len, (BUFFER_SIZE - len));
		if (ft_strlen(tmp) == 0)
			ft_free(&tmp, NULL);
	}
	else
		gnl->chunk = ft_strdup(to_split);
	free (*chunk_saved);
	*chunk_saved = tmp;
}

char	*get_next_line(int fd)
{
	static char		*chunk_saved;
	t_gnl			gnl;

	gnl.line = NULL;
	gnl.is_reading = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&chunk_saved, NULL));
	gnl.buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!gnl.buffer)
		return (NULL);
	while (gnl.is_reading)
	{
		ft_bzero(gnl.buffer, (BUFFER_SIZE + 1));
		if (!chunk_saved)
			gnl.is_reading = read(fd, gnl.buffer, BUFFER_SIZE);
		if (gnl.is_reading == -1)
			return (ft_free(&chunk_saved, &gnl));
		split(&chunk_saved, &gnl);
		append(&gnl);
	}
	ft_free(&gnl.buffer, NULL);
	if (gnl.is_reading == 0 && ft_strlen(gnl.line) == 0)
		ft_free(&gnl.line, NULL);
	return (gnl.line);
}
