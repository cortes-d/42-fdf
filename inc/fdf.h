/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:07:12 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 12:37:13 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

/* Error return codes. 
 */
# define ERROR_MLX 1
# define ERROR_MALLOC 1
# define ERROR_FILE 1

/* General configuration
 */
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1200
# define COLOR_START 0xFFFFFF
# define COLOR_END 0x00FF00
# define INT_MAX 2147483647
# define DEFAULT_SPACING 10
# define DEFAULT_ROTATION 15

/* t_img
 * MLX data related to the images.
 */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

/* t_pts
 * Data structure for the points.
 * xyz coordinates.
 * color of the point.
 */
typedef struct s_pts
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pts;

/* t_map
 * Contains the data related to the map.
 * Dimensions of the map.
 * Range of z axis (minimum and maximum).
 * Spacing of the grid.
 * Map as file (fil).
 * Map as array (arr).
 * Map as points (pts).
 */
typedef struct s_map
{
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	int			origin_x;
	int			origin_y;
	int			spacing;
	int			angle;
	char		*fil;
	char		***arr;
	t_pts		*pts;
	t_pts		*pts_original;
}	t_map;

typedef struct s_hook
{
	int	is_pressed;
	int	mouse_start_x;
	int	mouse_start_y;
	int	is_dragging_left;
	int	is_dragging_right;
	int	is_window_moved;
}	t_hook;

/* t_data
 * Contains all the data of fdf.
 */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*mlx_img;
	t_map	*map;
	t_hook	hook;
}	t_data;

void	ft_free_all(t_data **data);

#endif