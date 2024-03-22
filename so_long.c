/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:58:25 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/22 20:29:56 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#define WIDTH 1920
#define HEIGHT 1080
#define BPP sizeof(int32_t)

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (0);
}

// void	error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int	iswall(t_tile *map, int x, int y)
{
	t_tile	*tile;

	tile = map;
	if (!tile)
		return (-1);
	while (tile)
	{
		if (tile->x == x && tile->y == y)
		{
			if (tile->type == 1)
				return (1);
			else
				return (0);
		}
		tile = tile->next;
	}
	return (0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
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
}

void	render_tile(t_game *game, char c, int x, int y)
{
	if (c == '1')
		path_to_window(game->mlx, PATH_WATER, x, y);
	else
	{
		path_to_window(game->mlx, PATH_GRASS, x, y);
		if (c == 'P')
		{
			path_to_window(game->mlx, PATH_SHIBA, x, y);
			game->player->x = x;
			game->player->y = y;
		}
		else if (c == 'C')
		{
			path_to_window(game->mlx, PATH_FOOD, x, y);
			game->food->x = x;
			game->food->y = y;
		}
		else if (c == 'E')
		{
			path_to_window(game->mlx, PATH_HOUSE, x, y);
			game->house->x = x;
			game->house->y = y;
		}
	}
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	int			src;
	t_game		*game;

	if (argc != 2)
		return (-1);
	game = malloc(sizeof(t_game));
	game->player = malloc(sizeof(t_player));
	game->food = malloc(sizeof(t_food));
	game->house = malloc(sizeof(t_house));
	mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		ft_error("Error\nCannot initialize a map");
	else
		game->mlx = mlx;
	src = open(argv[1], O_RDONLY);
	if (draw_ber(src, game) == -1)
		ft_error("Error\nMap is not valid");
	is_p_c_e_in_one_map(game);
	mlx_key_hook(mlx, &my_keyhook, game);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

