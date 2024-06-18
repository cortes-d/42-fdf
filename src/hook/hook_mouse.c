/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:54:25 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/19 14:16:47 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hook.h"
#include "data.h"

int	ft_hook_mouse_press(int button, int x, int y, t_data *data)
{
	(void)data;
	if ((x >= 0 && x < WINDOW_WIDTH)
		&& (y >= 0 && y < WINDOW_HEIGHT))
	{
		if (button == MOUSE_LEFT)
		{
			data->hook.is_dragging_left = 1;
			data->hook.mouse_start_x = x;
			data->hook.mouse_start_y = y;
		}
		else if (button == MOUSE_RIGHT)
		{
			data->hook.is_dragging_right = 1;
			data->hook.mouse_start_x = x;
			data->hook.mouse_start_y = y;
		}
		else if (button == MOUSE_SCROLL_UP)
			ft_zoom(data, 1);
		else if (button == MOUSE_SCROLL_DOWN)
			ft_zoom(data, -1);
		else if (button == MOUSE_MIDDLE)
			ft_view_original(data);
	}
	return (0);
}

int	ft_hook_mouse_motion(int x, int y, t_data *data)
{
	int		offset_x;
	int		offset_y;
	double	divisor;

	offset_x = x - data->hook.mouse_start_x;
	offset_y = y - data->hook.mouse_start_y;
	if (data->hook.is_dragging_left)
	{
		divisor = 50;
		if (data->map->spacing != 0)
			divisor = 50 / data->map->spacing;
		ft_move(data, offset_x / divisor, offset_y / divisor);
	}
	else if (data->hook.is_dragging_right)
	{
		divisor = 250;
		if (data->map->spacing != 0)
			divisor = 250 / data->map->spacing;
		if (abs(offset_x) > abs(offset_y))
			ft_rotate(data, offset_x / divisor);
		if (abs(offset_y) > abs(offset_x))
			ft_rotate(data, offset_y / divisor);
	}
	return (0);
}

int	ft_hook_mouse_release(int button, int x, int y, t_data *data)
{
	(void)data;
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT)
		data->hook.is_dragging_left = 0;
	else if (button == MOUSE_RIGHT)
		data->hook.is_dragging_right = 0;
	return (0);
}
