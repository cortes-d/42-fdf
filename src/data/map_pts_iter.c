/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_pts_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:33:39 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/19 11:28:37 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

/* ft_map_pts_iter
 * Iterates through the 3D map.
 * Applies the function f for each point.
 */
void	ft_map_pts_iter(t_data *data, void (*f)(t_data *data, int row, int col))
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			f(data, i, j);
			j++;
		}
		i++;
	}
}
