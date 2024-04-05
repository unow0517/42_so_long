/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:59:59 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 21:21:22 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	move(t_game *game, int next_x, int next_y)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;
	mlx_t		*mlx;
	t_tile		*food;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, next_x, next_y)))
	{
		img_to_window(mlx, game->player_png, player->x, player->y);
		if (player->collect_cnt == game->food_cnt)
			img_to_window(mlx, game->food_png, player->x, player->y);
		ft_printf("%d\n", player->movements + 1);
		(player->movements)++;
	}
	food = find_tile_in_list(next_x, next_y, game->food_list);
	if (food && food->visited == 0)
	{
		printf("%d %d", food->x, food->y);
		game->player->collect_cnt++;
		food->visited = 1;
	}
}

void	move_up(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x, player->y - TILE_SIZE)))
	{
		player->y -= TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x, player->y + TILE_SIZE);
		if (house->x == player->x && house->y == player->y + TILE_SIZE)
			img_to_window(mlx, game->house_png,
				player->x, player->y + TILE_SIZE);
	}
}

void	move_down(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x, player->y + TILE_SIZE)))
	{
		player->y += TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x, player->y - TILE_SIZE);
		if (house->x == player->x && house->y == player->y - TILE_SIZE)
			img_to_window(mlx, game->house_png,
				player->x, player->y - TILE_SIZE);
	}
}

void	move_left(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x - TILE_SIZE, player->y)))
	{
		player->x -= TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x + TILE_SIZE, player->y);
		if (house->x == player->x + TILE_SIZE && house->y == player->y)
			img_to_window(mlx, game->house_png,
				player->x + TILE_SIZE, player->y);
	}
}

void	move_right(t_game *game)
{
	t_player	*player;
	t_tile		*map;
	t_house		*house;
	mlx_t		*mlx;

	player = game->player;
	map = game->map;
	house = game->house;
	mlx = game->mlx;
	if (!(iswall(map, player->x + TILE_SIZE, player->y)))
	{
		player->x += TILE_SIZE;
		move(game, player->x, player->y);
		img_to_window(mlx, game->grass_png, player->x - TILE_SIZE, player->y);
		if (house->x == player->x - TILE_SIZE && house->y == player->y)
			img_to_window(mlx, game->house_png,
				player->x - TILE_SIZE, player->y);
	}
}
