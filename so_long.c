#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include/so_long.h"
#define WIDTH 1920
#define HEIGHT 1080
#define BPP sizeof(int32_t)

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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
			if (tile->type == '1')
				return (1);
			else
				return (0);
		}
		tile = tile->next;
	}
	return (0);
}

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_game		*game;

	game = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(game);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(game);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
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
			path_to_window(game->mlx, PATH_FOOD, x, y);
		else if (c == 'E')
			path_to_window(game->mlx, PATH_HOUSE, x, y);
	}
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	int			src;
	t_game		*game;
	t_player	*player;

	if (argc != 2)
		return (-1);
	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();
	else
	{
		game->mlx = mlx;
		game->player = player;
	}

	src = open(argv[1], O_RDONLY);
	draw_ber(src, game);
	mlx_key_hook(mlx, &my_keyhook, game);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

