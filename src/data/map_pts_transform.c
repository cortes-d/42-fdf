/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pts_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:18:34 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:40:21 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "util.h"

/* ft_map_pts_transform
 * Transforms the list of 3D points.
 * Adds the spacing.
 */

typedef struct s_transform
{
	int		index;
	double	theta;
	double	adjusted_x;
	double	adjusted_y;
	double	rotated_x;
	double	rotated_y;
	double	origin_x;
	double	origin_y;
}	t_transform;

void	ft_map_pts_scale(t_data *data, int index)
{
	data->map->pts[index].x *= data->map->spacing;
	data->map->pts[index].y *= data->map->spacing;
	data->map->pts[index].z *= data->map->spacing;
}

void	ft_map_pts_translate(t_data *data, int index)
{
	data->map->pts[index].x += data->map->origin_x;
	data->map->pts[index].y += data->map->origin_y;
}

void	ft_map_pts_rotate(t_data *data, int index, double theta)
{
	t_transform	t;

	t.origin_x = data->map->width * data->map->spacing / 2;
	t.origin_y = data->map->height * data->map->spacing / 2;
	t.adjusted_x = data->map->pts[index].x - t.origin_x;
	t.adjusted_y = data->map->pts[index].y - t.origin_y;
	t.rotated_x = t.adjusted_x * cos(theta) - t.adjusted_y * sin(theta);
	t.rotated_y = t.adjusted_x * sin(theta) + t.adjusted_y * cos(theta);
	data->map->pts[index].x = t.rotated_x + t.origin_x;
	data->map->pts[index].y = t.rotated_y + t.origin_y
		- data->map->pts[index].z;
}

void	ft_map_pts_transform(t_data *data, int row, int col)
{
	t_transform	t;

	t.index = row * data->map->width + col;
	t.theta = to_radians(data->map->angle);
	ft_map_pts_scale(data, t.index);
	ft_map_pts_rotate(data, t.index, t.theta);
	ft_map_pts_translate(data, t.index);
}
