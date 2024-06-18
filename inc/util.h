/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:35:23 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:40:14 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "fdf.h"

char		*get_next_line(int fd);
double		to_radians(double degrees);
long long	atoi_hex(const char *str);

#endif