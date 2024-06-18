/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:26:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:39:07 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"

void	ft_map_arr_init(int i, char *line, t_data *data)
{
	data->map->arr[i] = ft_split(line, ' ');
	if (data->map->arr[i] == NULL)
	{
		ft_map_arr_free(data->map->arr, i);
		return ;
	}
	if (i == 0)
		data->map->width = ft_map_arr_count_cols(data->map->arr);
}
