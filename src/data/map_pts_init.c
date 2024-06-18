/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pts_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:33:43 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:40:01 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "data.h"

/*
 * ft_map_pts_init
 * Initializes a 3D point from the 2D array.
 * Initializes the z_min and z_max values.
 * Initializes the color value.
 * Frees the temporary split array.
 */
void	ft_map_pts_init(t_data *data, int row, int col)
{
	char	**split;
	int		index;
	int		i;

	index = row * data->map->width + col;
	data->map->pts_original[index].x = col;
	data->map->pts_original[index].y = row;
	split = ft_split(data->map->arr[row][col], ',');
	if (split == NULL)
		return ;
	data->map->pts_original[index].z = ft_atoi(split[0]);
	if (data->map->pts_original[index].z < data->map->z_min)
		data->map->z_min = data->map->pts_original[index].z;
	if (data->map->pts_original[index].z > data->map->z_max)
		data->map->z_max = data->map->pts_original[index].z;
	if (split[1] != NULL)
		data->map->pts_original[index].color = atoi_hex(split[1]);
	else
		data->map->pts_original[index].color = 0;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
