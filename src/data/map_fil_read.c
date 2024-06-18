/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fil_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:23:01 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:38:46 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "util.h"

/* ft_map_fil_read
 * Counts the number of rows and cols.
 * Stores the map file in a 2D array.
 * Sends the 2D array to a ft_map_arr_to_point3d()
 * that generates a list of 3D points.
 */
int	ft_map_fil_read(t_data *data)
{
	data->map->height = ft_map_fil_iter(data, ft_map_arr_void);
	if (data->map->height == 0)
	{
		ft_free_all(&data);
		exit (ERROR_FILE);
	}
	data->map->arr = malloc(sizeof(char **) * data->map->height);
	if (data->map->arr == NULL)
	{
		ft_free_all(&data);
		exit (ERROR_MALLOC);
	}
	ft_map_arr_zero(data);
	ft_map_fil_iter(data, ft_map_arr_init);
	ft_map_arr_to_pts(data);
	return (0);
}
