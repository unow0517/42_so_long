/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:58:15 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/20 12:28:30 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void draw_ber(int src, t_game *game)
{
	char			*gnl;
	int				next_x;
	int				next_y;
	t_tile			*tile;

	tile = malloc(sizeof(t_tile));
	gnl = get_next_line(src);
	next_x = 0;
	next_y = 0;
	tile = ft_map_lstnew(*gnl);
	tile->type = 0;
	tile->x = 0;
	tile->y = 0;

	while (*gnl != 0)
	{
		if (*gnl == '\n')
		{
			next_x = 0;
			next_y += 128;
			gnl = get_next_line(src);
		}
		else
		{
			tile_to_map_list(*gnl, &tile, next_x, next_y);
			render_tile(game, *gnl, next_x, next_y);
			next_x += 128;
			gnl++;
		}
	}
	game->map = tile;
}

