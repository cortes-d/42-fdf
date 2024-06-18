/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:08:31 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:29 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_gfx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}
