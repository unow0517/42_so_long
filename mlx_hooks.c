/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:53:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 21:18:48 by yowoo            ###   ########.fr       */
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
		ft_printf("GAME SHUT DOWN!");
		system("leaks so_long");
		exit(0);
	}
}

static void	finish_game(void *param)
{
	t_game		*game;
	t_player	*player;
	// t_food		*food;
	t_house		*house;

	game = param;
	player = game->player;
	// food = game->food;
	house = game->house;
	printf("cltcnt %d\n",player->collect_cnt);
	if (player->x == house->x && player->y == house->y)
	{
		printf("fdcnt: %d, player->collect: %d\n", game->food_cnt, player->collect_cnt);
		if (player->collect_cnt >= game->food_cnt)
		{
			ft_printf("SHIBA ESCAPED WITH THE FOOD!");
			system("leaks so_long");
			exit(0);
		}
	}
}

void	mlx_hooks(t_game *game)
{
	mlx_t	*mlx;

	mlx = game->mlx;
	mlx_key_hook(mlx, &my_keyhook, game);
	mlx_loop_hook(mlx, &finish_game, game);
	mlx_loop(mlx);
}