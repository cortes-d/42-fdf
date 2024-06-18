/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:35:01 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:29 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hook.h"
#include "data.h"
#include "graphic.h"

void	ft_rotate(t_data *data, int angle)
{
	data->map->angle += angle;
	ft_gfx_render(data);
}

void	ft_zoom(t_data *data, int zoom)
{
	if (data->map->spacing + zoom < 0)
		return ;
	if (data->map->spacing + zoom > 50)
		return ;
	data->map->spacing += zoom;
	ft_gfx_render(data);
}

void	ft_view_original(t_data *data)
{
	data->map->origin_x = WINDOW_WIDTH / 2;
	data->map->origin_y = WINDOW_HEIGHT / 2;
	data->map->spacing = DEFAULT_SPACING;
	data->map->angle = DEFAULT_ROTATION;
	ft_gfx_render(data);
}

void	ft_move(t_data *data, int move_x, int move_y)
{
	data->map->origin_x += move_x;
	data->map->origin_y += move_y;
	ft_gfx_render(data);
}

void	ft_exit(t_data **data)
{
	ft_free_all(data);
	exit(0);
}
