/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:58:15 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/21 12:43:53 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	mid_wall_check(char *str, int len)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (-1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
		if ((str[i] == '\n' || str[i] == '\0') && str[i - 1] != '1')
		{
			i--;
			return (-1);
		}
	}
	if (i != len)
		return (-1);
	return (0);
}

int	end_wall_check(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	if (i != len)
		return (-1);
	return (0);
}

int	draw_ber(int src, t_game *game)
{
	char			*gnl;
	int				next_x;
	int				next_y;
	char			*lastgnl;
	int				len;

	gnl = get_next_line(src);
	len = ft_strlen(gnl) - 1;
	next_x = 0;
	next_y = 0;
	game->map = ft_map_lstnew(*gnl);
	if (end_wall_check(gnl, len) == -1)
		return (-1);
	while (*gnl != 0)
	{
		if (*gnl == '\n')
		{
			next_x = 0;
			next_y += 128;
			lastgnl = gnl;
			gnl = get_next_line(src);
			if (!gnl && end_wall_check(lastgnl, len) == -1)
				return (-1);
			if (gnl && mid_wall_check(gnl, len) == -1)
				return (-1);
		}
		else
		{
			tile_to_map_list(*gnl, &game->map, next_x, next_y);
			render_tile(game, *gnl, next_x, next_y);
			next_x += 128;
			gnl++;
		}
	}
	return (0);
}

