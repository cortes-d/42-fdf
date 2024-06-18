/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcortes <dcortes@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:52:26 by dcortes           #+#    #+#             */
/*   Updated: 2024/06/18 14:30:24 by dcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

long long	atoi_hex(const char *str)
{
	char		*charset;
	char		*str_lowercase;
	char		*tmp;
	long long	result;

	str_lowercase = ft_strdup(str);
	tmp = str_lowercase;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	tmp = str_lowercase;
	if (ft_strncmp(tmp, "0x", 2) == 0)
		tmp += 2;
	charset = "0123456789abcdef";
	result = ft_atoi_base(tmp, charset);
	free(str_lowercase);
	return (result);
}
