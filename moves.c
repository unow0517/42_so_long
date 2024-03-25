/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:59:59 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/25 11:46:31 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// move(game, x, y - 128)
static void	move(t_game *game, int next_x, int next_y)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;

	player = game->player;
	map = game->map;
	house = game->house;
	if (!(iswall(map, next_x, next_y)))
	{
		path_to_window(game->mlx, PATH_SHIBA, player->x, player->y);
		if (player->if_collect == 1)
			path_to_window(game->mlx, PATH_FOOD, player->x, player->y);
		ft_printf("%d\n", player->movements + 1);
		(player->movements)++;
	}
}

void	move_up(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;

	player = game->player;
	map = game->map;
	house = game->house;
	if (!(iswall(map, player->x, player->y - 128)))
	{
		player->y -= 128;
		move(game, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x, player->y + 128);
		if (house->x == player->x && house->y == player->y + 128)
			path_to_window(game->mlx, PATH_HOUSE, player->x, player->y + 128);
	}
}

void	move_down(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;

	player = game->player;
	map = game->map;
	house = game->house;
	if (!(iswall(map, player->x, player->y + 128)))
	{
		player->y += 128;
		move(game, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x, player->y - 128);
		if (house->x == player->x && house->y == player->y - 128)
			path_to_window(game->mlx, PATH_HOUSE, player->x, player->y - 128);
	}
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;

	player = game->player;
	map = game->map;
	house = game->house;
	if (!(iswall(map, player->x - 128, player->y)))
	{
		player->x -= 128;
		move(game, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x + 128, player->y);
		if (house->x == player->x + 128 && house->y == player->y)
			path_to_window(game->mlx, PATH_HOUSE, player->x + 128, player->y);
	}

}

void	move_right(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;

	player = game->player;
	map = game->map;
	house = game->house;
	if (!(iswall(map, player->x + 128, player->y)))
	{
		player->x += 128;
		move(game, player->x, player->y);
		path_to_window(game->mlx, PATH_GRASS, player->x - 128, player->y);
		if (house->x == player->x - 128 && house->y == player->y)
			path_to_window(game->mlx, PATH_HOUSE, player->x - 128, player->y);
	}

}
