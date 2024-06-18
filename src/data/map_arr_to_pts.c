/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr_to_pts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:15:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:38:41 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "util.h"

void	ft_map_arr_to_pts(t_data *data)
{
	data->map->pts_original = malloc(sizeof(t_pts)
			* data->map->height * data->map->width);
	if (data->map->pts_original == NULL)
		return ;
	ft_map_pts_iter(data, ft_map_pts_init);
	ft_map_pts_iter(data, ft_map_pts_color_init);
	ft_map_arr_free2(data);
}
