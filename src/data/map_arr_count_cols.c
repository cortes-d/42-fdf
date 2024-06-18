/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_arr_count_cols.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:00 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/12 13:15:35 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

/* ft_map_count_cols
 * Counts the number of rows in the map file.
 * Useful to know the width of the map (X-axis).
 */
int	ft_map_arr_count_cols(char ***map_arr)
{
	int	i;

	i = 0;
	while (map_arr[0][i])
		i++;
	return (i);
}
