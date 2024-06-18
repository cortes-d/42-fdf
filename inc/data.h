/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:11:23 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 12:36:56 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "fdf.h"

/* ft_map_fil_
 * Functions related to the map as a file.
 */
int		ft_map_fil_read(t_data *data);
int		ft_map_fil_iter(t_data *data,
			void (*f)(int i, char *line, t_data *data));

/* ft_map_arr_
 * Functions related to the map as a 2d array.
 */

void	ft_map_arr_init(int i, char *line, t_data *data);
void	ft_map_arr_void(int i, char *line, t_data *data);
void	ft_map_arr_zero(t_data *data);
int		ft_map_arr_count_cols(char ***map_arr);
void	ft_map_arr_to_pts(t_data *data);
void	ft_map_arr_free(char ***map_arr, int i);
void	ft_map_arr_free2(t_data *data);

/* ft_map_pts_
 * Functions related to the map as 3d points.
 */

void	ft_map_pts_iter(t_data *data,
			void (*f)(t_data *data, int row, int col));
void	ft_map_pts_transform(t_data *data, int row, int col);
void	ft_map_pts_init(t_data *data, int row, int col);
void	ft_map_pts_color_init(t_data *data, int row, int col);
t_pts	*ft_map_pts_copy(t_pts *original, int size);
void	ft_map_pts_display(t_data *data, int row, int col);

/* freeing functions
 */

void	ft_free_point3d(t_map *map, int i);
void	ft_free_all(t_data **data);
void	ft_map_pts_free(t_data **data);
void	ft_map_pts_original_free(t_data **data);
void	ft_map_pts_print(t_data *data);

#endif
