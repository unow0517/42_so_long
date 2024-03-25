/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:58:25 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/25 12:03:04 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit (0);
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
			if (tile->type == 1)
				return (1);
			else
				return (0);
		}
		tile = tile->next;
	}
	return (0);
}



char	*get_map_size(char **argv, t_game *game)
{
	char	*gnl;
	int		len;
	char	*whole_string;
	int		src;
	int		height;

	height = 0;
	whole_string = "";
	src = open(argv[1], O_RDONLY);
	gnl = get_next_line(src);
	len = ft_strlen(gnl);
	game->width = len - 1;
	while (gnl)
	{
		gnl = get_next_line(src);
		height++;
	}
	game->height = height;
	return (0);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	int			src;
	t_game		*game;

	if (argc != 2)
		return (-1);
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error\nCannot initialize a game");
	game = game_init(game);
	get_map_size(argv, game);
	src = open(argv[1], O_RDONLY);
	mlx = mlx_init(128 * game->width, 128 * game->height, "Test", false);
	if (!mlx)
		ft_error("Error\nCannot initialize a map");
	else
		game->mlx = mlx;
	if (draw_ber(src, game) == -1)
		ft_error("Error\nMap is not valid");
	error_check(game);
	mlx_hooks(game);
	frees_game(game);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
