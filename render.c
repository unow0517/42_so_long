/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:19:04 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 22:43:07 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	add_object(t_game *game, int x, int y, char c)
{
	t_tile	*food_list;

	food_list = game->food_list;
	if (c == 'P')
	{
		img_to_window(game->mlx, game->player_png, x, y);
		game->player->x = x;
		game->player->y = y;
		game->player_cnt++;
	}
	else if (c == 'C')
	{
		img_to_window(game->mlx, game->food_png, x, y);
		ft_map_lstadd_back(&food_list, ft_map_lstnew(c, x, y));
		game->food_list->x = x;
		game->food_list->y = y;
		game->food_cnt++;
	}
	else if (c == 'E')
	{
		img_to_window(game->mlx, game->house_png, x, y);
		game->house->x = x;
		game->house->y = y;
		game->house_cnt++;
	}
}

void	render_tile(t_game *game, char c, int x, int y)
{
	if (c == '1')
		img_to_window(game->mlx, game->water_png, x, y);
	else
	{
		img_to_window(game->mlx, game->grass_png, x, y);
		add_object(game, x, y, c);
	}
}

void	render_and_list(char c, t_game *game, int next_x, int next_y)
{
	tile_to_map_list(c, &game->map, next_x, next_y);
	render_tile(game, c, next_x, next_y);
}

void	load_pngs(t_game *game)
{
	game->player_png = mlx_load_png(PATH_SHIBA);
	game->food_png = mlx_load_png(PATH_FOOD);
	game->house_png = mlx_load_png(PATH_HOUSE);
	game->grass_png = mlx_load_png(PATH_GRASS);
	game->water_png = mlx_load_png(PATH_WATER);
}
