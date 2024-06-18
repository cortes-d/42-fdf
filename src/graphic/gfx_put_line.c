/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_put_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:10:07 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:27 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	total_steps;
}	t_bresenham;

static t_bresenham	init_bresenham(t_pts p1, t_pts p2)
{
	t_bresenham	b;

	b.dx = abs(p2.x - p1.x);
	b.dy = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		b.sx = 1;
	else
		b.sx = -1;
	if (p1.y < p2.y)
		b.sy = 1;
	else
		b.sy = -1;
	b.err = b.dx - b.dy;
	return (b);
}

unsigned int	interpolate(unsigned int color1,
	unsigned int color2, double factor)
{
	t_rgb	c1;
	t_rgb	c2;
	t_rgb	result;

	c1.r = (color1 >> 16) & 0xFF;
	c1.g = (color1 >> 8) & 0xFF;
	c1.b = color1 & 0xFF;
	c2.r = (color2 >> 16) & 0xFF;
	c2.g = (color2 >> 8) & 0xFF;
	c2.b = color2 & 0xFF;
	result.r = (unsigned int)(c1.r + factor * (c2.r - c1.r));
	result.g = (unsigned int)(c1.g + factor * (c2.g - c1.g));
	result.b = (unsigned int)(c1.b + factor * (c2.b - c1.b));
	return ((result.r << 16) | (result.g << 8) | result.b);
}

void	ft_gfx_draw_line(t_img *img, t_pts *p1, t_pts p2, t_bresenham *b)
{
	int		current_step;
	double	factor;
	int		interpolated_color;

	current_step = 0;
	while (1)
	{
		factor = (double)current_step / b->total_steps;
		interpolated_color = interpolate(p1->color, p2.color, factor);
		ft_gfx_put_pixel(img, p1->x, p1->y, interpolated_color);
		if (p1->x == p2.x && p1->y == p2.y)
			break ;
		b->e2 = 2 * b->err;
		if (b->e2 > -b->dy)
		{
			b->err -= b->dy;
			p1->x += b->sx;
		}
		if (b->e2 < b->dx)
		{
			b->err += b->dx;
			p1->y += b->sy;
		}
		current_step++;
	}
}

void	ft_gfx_put_line(t_img *img, t_pts p1, t_pts p2)
{
	t_bresenham	b;

	b = init_bresenham(p1, p2);
	if (abs(p1.x - p2.x) > abs(p1.y - p2.y))
		b.total_steps = abs(p1.x - p2.x);
	else
		b.total_steps = abs(p1.y - p2.y);
	ft_gfx_draw_line(img, &p1, p2, &b);
}
