/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fil_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:28:48 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:38:44 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "util.h"

/* ft_map_file_iter
 * Reads the map file and terates through it.
 * Applies a function f().
 * Also counts the number of rows in the map file.
 * Useful to know the height of the map (Y-axis).
 */
int	ft_map_fil_iter(t_data *data, void (*f)(int i, char *line, t_data *data))
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->map->fil, O_RDONLY);
	if (fd == -1)
		return (0);
	i = -1;
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			break ;
		i++;
		f(i, line, data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i + 1);
}
