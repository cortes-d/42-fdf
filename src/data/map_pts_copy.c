/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_pts_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:32:38 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/12 15:32:39 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_pts	*ft_map_pts_copy(t_pts *original, int size)
{
	t_pts	*copy;
	int		i;

	copy = malloc(sizeof(t_pts) * size);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = original[i];
		i++;
	}
	return (copy);
}
