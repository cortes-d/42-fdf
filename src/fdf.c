/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:26:29 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:30:46 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include "util.h"
#include "data.h"
#include "graphic.h"
#include "hook.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_DIR "map/"
#define WINDOW_CLOSE 17
#define MOUSE_PRESS 4
#define MOUSE_RELEASE 5
#define MOUSE_MOTION 6
#define KEY_PRESS 2
#define KEY_RELEASE 3

/* init_data
 * Initializes the data structure.
 * What can go wrong ?
 * 	- Malloc fails.
 * What should we do ?
 * 	- No freeing needed at this stage.
 * 	- Exit with error code.
 */
t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(ERROR_MALLOC);
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->mlx_img = NULL;
	data->map = NULL;
	return (data);
}

/* init_map
 * Initializes the map structure.
 * What can go wrong ?
 * 	- Malloc fails.
 * 	- File does not exist.
 * What should we do ?
 * 	- Free the map structure.
 * 	- Free the data structure.
 * 	- Exit with error code.
 */

static void	init_map_default(t_data *data)
{
	data->map->width = 0;
	data->map->height = 0;
	data->map->z_max = 0;
	data->map->z_min = INT_MAX;
	data->map->origin_x = WINDOW_WIDTH / 2;
	data->map->origin_y = WINDOW_HEIGHT / 2;
	data->map->spacing = DEFAULT_SPACING;
	data->map->angle = DEFAULT_ROTATION;
	data->map->fil = NULL;
	data->map->arr = NULL;
	data->map->pts = NULL;
	data->map->pts_original = NULL;
	data->hook.is_pressed = 0;
	data->hook.mouse_start_x = 0;
	data->hook.mouse_start_y = 0;
	data->hook.is_dragging_left = 0;
	data->hook.is_dragging_right = 0;
	data->hook.is_window_moved = 0;
}

void	init_map(char **argv, t_data *data)
{
	int	fd;

	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		ft_free_all(&data);
		exit(ERROR_MALLOC);
	}
	init_map_default(data);
	data->map->fil = ft_strjoin(MAP_DIR, argv[1]);
	if (!data->map->fil)
	{
		ft_free_all(&data);
		exit(ERROR_MALLOC);
	}
	fd = open(data->map->fil, O_RDONLY);
	if (fd == -1)
	{
		ft_free_all(&data);
		exit(ERROR_FILE);
	}
}

/* init_mlx
 * Initializes the mlx pointers.
 */
int	init_mlx(t_data *data)
{
	data->mlx_img = malloc(sizeof(t_img));
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (data->mlx_img == NULL || data->mlx_ptr == NULL || data->mlx_win == NULL)
	{
		ft_free_all(&data);
		exit(ERROR_MLX);
	}
	data->mlx_img->img = mlx_new_image(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx_img->addr = mlx_get_data_addr(data->mlx_img->img,
			&data->mlx_img->bpp, &data->mlx_img->line_length,
			&data->mlx_img->endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = init_data();
		init_map(argv, data);
		init_mlx(data);
		ft_map_fil_read(data);
		ft_gfx_render(data);
		mlx_hook(data->mlx_win, WINDOW_CLOSE, 0, ft_hook_window_close, data);
		mlx_hook(data->mlx_win, MOUSE_PRESS, 0, ft_hook_mouse_press, data);
		mlx_hook(data->mlx_win, MOUSE_MOTION, 0, ft_hook_mouse_motion, data);
		mlx_hook(data->mlx_win, MOUSE_RELEASE, 0, ft_hook_mouse_release, data);
		mlx_hook(data->mlx_win, KEY_PRESS, 0, ft_hook_key_press, data);
		mlx_hook(data->mlx_win, KEY_RELEASE, 0, ft_hook_key_release, data);
		mlx_loop(data->mlx_ptr);
		ft_free_all(&data);
	}
	return (0);
}
