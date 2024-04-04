/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/04 11:52:00 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// frees_game(game);
		system("leaks so_long");
		exit(0);
	}
}

static void	finish_game(void *param)
{
	t_game		*game;
	t_player	*player;
	t_food		*food;
	t_house		*house;

	game = param;
	player = game->player;
	food = game->food;
	house = game->house;
	if (player->x == food->x && player->y == food->y)
		player->if_collect = 1;
	if (player->x == house->x && player->y == house->y)
		if (player->if_collect == 1)
		{
			// frees_game(game);
			system("leaks so_long");
			exit(0);
		}
}

void	mlx_hooks(t_game *game)
{
	mlx_t	*mlx;

	mlx = game->mlx;
	mlx_key_hook(mlx, &my_keyhook, game);
	if (mlx_loop_hook(mlx, &finish_game, game))
		printf("SHIBA ESCAPED WITH THE FOOD!");
	mlx_loop(mlx);
}