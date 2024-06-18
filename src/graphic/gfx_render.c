/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:32:33 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:28 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "graphic.h"
#include "data.h"

int	ft_gfx_render(t_data *data)
{
	ft_gfx_put_background(data->mlx_img, 0x000000);
	mlx_put_image_to_window(data->mlx_ptr,
		data->mlx_win, data->mlx_img->img, 0, 0);
	ft_map_pts_free(&data);
	data->map->pts = ft_map_pts_copy(data->map->pts_original,
			data->map->height * data->map->width);
	ft_map_pts_iter(data, ft_map_pts_transform);
	ft_gfx_flood_fill(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->mlx_win, data->mlx_img->img, 0, 0);
	return (0);
}
