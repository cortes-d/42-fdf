/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_window_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:02 by dcortes           #+#    #+#             */
/*   Updated: 2024/02/19 11:45:37 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "data.h"

int	ft_hook_window_close(t_data *data)
{
	ft_exit(&data);
	return (0);
}
