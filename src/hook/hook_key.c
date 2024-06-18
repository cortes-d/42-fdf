/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:27:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:30 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hook.h"
#include "data.h"
#include "graphic.h"

int	ft_hook_key_press(int keycode, t_data *data)
{
	data->hook.is_pressed = 1;
	if (keycode == KEY_Q)
		ft_rotate(data, -5);
	else if (keycode == KEY_E)
		ft_rotate(data, 5);
	else if (keycode == KEY_W)
		ft_move(data, 0, -20);
	else if (keycode == KEY_S)
		ft_move(data, 0, 20);
	else if (keycode == KEY_A)
		ft_move(data, -10, 0);
	else if (keycode == KEY_D)
		ft_move(data, 10, 0);
	else if (keycode == KEY_Z)
		ft_zoom(data, 1);
	else if (keycode == KEY_X)
		ft_zoom(data, -1);
	else if (keycode == KEY_C)
		ft_view_original(data);
	else if (keycode == KEY_ESC)
		ft_exit(&data);
	return (0);
}

int	ft_hook_key_release(int keycode, t_data *data)
{
	(void)keycode;
	data->hook.is_pressed = 0;
	return (0);
}
