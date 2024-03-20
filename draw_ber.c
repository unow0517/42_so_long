/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:58:15 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/20 14:22:47 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	draw_ber(int src, t_game *game)
{
	char			*gnl;
	int				next_x;
	int				next_y;

	gnl = get_next_line(src);
	next_x = 0;
	next_y = 0;
	game->map = ft_map_lstnew(*gnl);

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
			tile_to_map_list(*gnl, &game->map, next_x, next_y);
			render_tile(game, *gnl, next_x, next_y);
			next_x += 128;
			gnl++;
		}
	}
}

