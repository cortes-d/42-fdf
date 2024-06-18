/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_pts_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:27:16 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/19 11:37:51 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
/*
void	ft_map_pts_free(t_data *data, int row, int col)
{
	int	index;

	index = row * data->map->width + col;
	if (data->map->pts)
	{
		free(&data->map->pts[index]);
		data->map->pts = NULL;
	}
}

void	ft_map_pts_original_free(t_data *data, int row, int col)
{
	int	index;

	index = row * data->map->width + col;
	if (data->map->pts_original)
	{
		free(&data->map->pts_original[index]);
		data->map->pts_original = NULL;
	}
}
*/

void	ft_map_pts_free(t_data **data)
{
	if ((*data)->map->pts)
	{
		free((*data)->map->pts);
		(*data)->map->pts = NULL;
	}
}

void	ft_map_pts_original_free(t_data **data)
{
	if ((*data)->map->pts_original)
	{
		free((*data)->map->pts_original);
		(*data)->map->pts_original = NULL;
	}
}
