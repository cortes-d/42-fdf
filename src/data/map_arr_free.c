/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_arr_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:27:04 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/19 13:44:35 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	ft_map_arr_free(char ***map_arr, int i)
{
	while (i >= 0)
	{
		free(map_arr[i]);
		i--;
	}
	free(map_arr);
}
/*
void	ft_map_arr_free2(t_data *data)
{
	int	i;
	int	j;

	if (data->map->arr == NULL)
		return ;
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			free(data->map->arr[i][j]);
			j++;
		}
		i++;
	}
	free(*data->map->arr);
	*data->map->arr = NULL;
}
*/

void	ft_map_arr_free2(t_data *data)
{
	int	i;
	int	j;

	if (data->map->arr == NULL)
		return ;
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			free(data->map->arr[i][j]);
			j++;
		}
		free(data->map->arr[i]);
		i++;
	}
	free(data->map->arr);
	data->map->arr = NULL;
}
