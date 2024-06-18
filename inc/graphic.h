/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:08:15 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 11:19:23 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "fdf.h"

int				ft_gfx_render(t_data *data);
void			ft_gfx_put_pixel(t_img *img, int x, int y, int color);
void			ft_gfx_put_line(t_img *img, t_pts p1, t_pts p2);
void			ft_gfx_flood_fill(t_data *data);
void			ft_gfx_put_background(t_img *img, int color);

#endif