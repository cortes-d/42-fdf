/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_arr_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:28:44 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/12 17:39:08 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	ft_map_arr_zero(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		data->map->arr[i] = NULL;
		i++;
	}
}
