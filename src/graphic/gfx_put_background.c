/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_put_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:42 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:31 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_gfx_put_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			ft_gfx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}
