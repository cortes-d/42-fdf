/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_pts_color_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:17:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/14 12:07:00 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

/* ft_map_pts_color_init
 * Initializes the color of each point3d in the map.
 * The color is calculated as a ratio of the z value and the z_max value.
 */
void	ft_map_pts_color_init(t_data *data, int row, int col)
{
	double	color;
	double	z_ratio;
	int		index;

	index = row * data->map->width + col;
	if (data->map->pts_original[index].color == 0)
	{
		z_ratio = data->map->pts_original[index].z / (double)data->map->z_max;
		color = (COLOR_START + (int)((COLOR_END - COLOR_START) * z_ratio));
		data->map->pts_original[index].color = (int)color;
	}
}

/*
void	ft_map_pts_color_init(t_data *data, int row, int col)
{
    double	color;
    double	z_ratio;
    int		index;
    int		color_step;
	int n = 15;
	// int n = COLOR_END - COLOR_START;

    index = row * data->map->width + col;
    if (data->map->pts_original[index].color == 0)
    {
        z_ratio = data->map->pts_original[index].z / (double)data->map->z_max;
        color_step = (COLOR_END - COLOR_START) / n;
        color = COLOR_START + color_step * (int)(z_ratio * n);
        data->map->pts_original[index].color = (int)color;
    }
}
*/