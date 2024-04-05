/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:16 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 20:41:58 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_game	*game_init(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (0);
	game->food = malloc(sizeof(t_food));
	if (!game->food)
		return (0);
	game->house = malloc(sizeof(t_house));
	if (!game->house)
		return (0);
	game->water = malloc(sizeof(t_water));
	if (!game->water)
		return (0);
	game->grass = malloc(sizeof(t_grass));
	if (!game->grass)
		return (0);
	game->food_list = malloc(sizeof(t_tile));
	if (!game->food_list)
		return (0);
	game->food_list->visited = 0;
	game->food_list->x = 0;				
	game->food_list->y = 0;				
	game->food_list->next = 0;				
	game->player_cnt = 0;
	game->player->movements = 0;
	game->player->collect_cnt = 0;
	game->food_cnt = 0;
	game->house_cnt = 0;
	game->width = 1;
	game->height = 1;
	return (game);
}

void	load_pngs(t_game *game)
{
	game->player_png = mlx_load_png(PATH_SHIBA);
	game->food_png = mlx_load_png(PATH_FOOD);
	game->house_png = mlx_load_png(PATH_HOUSE);
	game->grass_png = mlx_load_png(PATH_GRASS);
	game->water_png = mlx_load_png(PATH_WATER);
}
