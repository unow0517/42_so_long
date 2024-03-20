/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:59:59 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/20 13:09:21 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	move_up(t_game *game)
{
	t_player	*player;
	t_tile		*map;

	player = game->player;
	map = game->map;
	if (!(iswall(map, player->x, player->y - 128)))
	{
		player->y -= 128;
		path_to_window(game->mlx, PATH_SHIBA, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x, player->y + 128);
	}
}

void	move_down(t_game *game)
{
	t_player	*player;
	t_tile		*map;

	player = game->player;
	map = game->map;
	if (!(iswall(map, player->x, player->y + 128)))
	{
		player->y += 128;
		path_to_window(game->mlx, PATH_SHIBA, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x, player->y - 128);
	}
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_tile		*map;

	player = game->player;
	map = game->map;
	if (!(iswall(map, player->x - 128, player->y)))
	{
		player->x -= 128;
		path_to_window(game->mlx, PATH_SHIBA, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x + 128, player->y);
	}
}

void	move_right(t_game *game)
{
	t_player	*player;
	t_tile		*map;

	player = game->player;
	map = game->map;
	if (!(iswall(map, player->x + 128, player->y)))
	{
		player->x += 128;
		path_to_window(game->mlx, PATH_SHIBA, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x - 128, player->y);
	}
}