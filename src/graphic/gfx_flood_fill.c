/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_flood_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:22:11 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:26 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "data.h"

/* ft_flood_fill
 * Draws the map.
 * i.e. draws lines between each point of the map.
 */
static void	ft_gfx_draw_line_right(t_data *data, int row, int col)
{
	int	index;

	index = row * data->map->width + col;
	if (col + 1 < data->map->width)
		ft_gfx_put_line(data->mlx_img, data->map->pts[index],
			data->map->pts[index + 1]);
}

static void	ft_gfx_draw_line_down(t_data *data, int row, int col)
{
	int	index;

	index = row * data->map->width + col;
	if (row + 1 < data->map->height)
		ft_gfx_put_line(data->mlx_img, data->map->pts[index],
			data->map->pts[index + data->map->width]);
}

void	ft_gfx_flood_fill(t_data *data)
{
	ft_map_pts_iter(data, ft_gfx_draw_line_right);
	ft_map_pts_iter(data, ft_gfx_draw_line_down);
}
