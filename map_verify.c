/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/20 14:15:32 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	mid_check(size_t len, char *gnl)
{
	if (ft_strlen(gnl) != len)
		return (-1);
	if (*gnl != 1)
		return (-1);
	while (*gnl != '\n')
	{
		if (*(gnl + 1) == '\n' && *gnl != '1')
			return (-1);
		gnl++;
	}
	return (0);
}

int	last_check(size_t len, char *gnl)
{
	if (ft_strlen(gnl) != len)
		return (-1);
	while (*gnl != '\n')
	{
		if (*gnl != 1)
			return (-1);
		gnl++;
	}
	return (0);
}

int	map_verify(int src)
{
	char	*gnl;
	int		width;
	char	*lastgnl;

	width = 0;
	if (!src)
		return (0);
	gnl = get_next_line(src);
	while (*gnl != '\n')
	{
		if (*gnl != 1)
			return (-1);
		width++;
		gnl++;
	}
	width = width - 1;
	gnl = get_next_line(src);
	while (gnl != 0)
	{
		if (!(mid_check(width, gnl)))
			return (-1);
		lastgnl = gnl;
		gnl = get_next_line(src);
	}
	if (gnl == 0)
	{
		if (!(last_check(width, lastgnl)))
			return (-1);
		else
			return (0);
	}
	return (0);
}



