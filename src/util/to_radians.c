/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_radians.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:23:45 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:29:18 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

/*
 * Converts degrees to radians.
 */
double	to_radians(double degrees)
{
	return (degrees * (M_PI / 180));
}
