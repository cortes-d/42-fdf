/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:34:01 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:30:56 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "util.h"

typedef struct s_gnl
{
	int		is_reading;
	char	*buffer;
	char	*line;
	char	*chunk;
}	t_gnl;

char	*get_next_line(int fd);

#endif