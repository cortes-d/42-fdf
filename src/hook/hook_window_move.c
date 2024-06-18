/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_window_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:57:13 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/14 15:19:04 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "data.h"

int	ft_hook_window_move(t_data *data)
{
	data->hook.is_window_moved = 1;
	return (0);
}
