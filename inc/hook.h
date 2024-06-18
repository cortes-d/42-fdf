/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:25:11 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/15 16:04:25 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define KEY_ESC 53
# define KEY_TOP_ARROW 126
# define KEY_BOTTOM_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_O 31
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_MIDDLE 3

# include "data.h"

void	ft_rotate(t_data *data, int angle);
void	ft_zoom(t_data *data, int zoom);
void	ft_move(t_data *data, int move_x, int move_y);
void	ft_exit(t_data **data);
void	ft_view_original(t_data *data);

int		ft_hook_key_press(int keycode, t_data *data);
int		ft_hook_key_release(int keycode, t_data *data);
int		ft_hook_mouse(int mousecode, int x, int y, t_data *data);
int		ft_hook_mouse_press(int button, int x, int y, t_data *data);
int		ft_hook_mouse_motion(int x, int y, t_data *data);
int		ft_hook_mouse_release(int button, int x, int y, t_data *data);
int		ft_hook_window_close(t_data *data);
int		ft_hook_window_move(t_data *data);
int		ft_hook_no_action(t_data *data);

#endif