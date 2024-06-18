/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:01 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:38:23 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "data.h"
#include "util.h"

/* ft_free_all
 * Step 01 : frees the map structure.
 * Step 02 : frees the mlx pointers.
 * Step 03 : frees the data structure.
 * Note : for some reason, the mlx_destroy_image function 
 * needed to be called after the freeing of the mlx_ptr.
 * Otherwise, there are some memory leaks.
 * That's strange, one would expect the opposite.
 */

static void	ft_free_map(t_data **data)
{
	if ((*data)->map->fil)
	{
		free((*data)->map->fil);
		(*data)->map->fil = NULL;
	}
	if ((*data)->map->arr)
		ft_map_arr_free2(*data);
	if ((*data)->map->pts)
		ft_map_pts_free(data);
	if ((*data)->map->pts_original)
		ft_map_pts_original_free(data);
	if ((*data)->map)
	{
		free((*data)->map);
		(*data)->map = NULL;
	}
}

void	ft_free_all(t_data **data)
{
	if (*data)
	{
		if ((*data)->map)
			ft_free_map(data);
		if ((*data)->mlx_img)
		{
			mlx_destroy_image((*data)->mlx_ptr, (*data)->mlx_img->img);
			free((*data)->mlx_img);
			(*data)->mlx_img = NULL;
		}
		if ((*data)->mlx_win)
		{
			mlx_destroy_window((*data)->mlx_ptr, (*data)->mlx_win);
			(*data)->mlx_win = NULL;
		}
		free(*data);
		*data = NULL;
	}
}
