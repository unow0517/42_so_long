/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:16 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/06 11:40:16 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	player_init(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_error("Error\n error allocating memory for game");
	game->player_cnt = 0;
	game->player->movements = 0;
	game->player->collect_cnt = 0;
}

static void	object_init(t_game *game)
{
	game->food = malloc(sizeof(t_object));
	if (!game->food)
		ft_error("Error\n error allocating memory for game");
	game->house = malloc(sizeof(t_object));
	if (!game->house)
		ft_error("Error\n error allocating memory for game");
}

static void	objectlist_init(t_game *game)
{
	game->water = malloc(sizeof(t_objectlist));
	if (!game->water)
		ft_error("Error\n error allocating memory for game");
	game->grass = malloc(sizeof(t_objectlist));
	if (!game->grass)
		ft_error("Error\n error allocating memory for game");
}

static void	foodlist_init(t_game *game)
{
	game->food_list = malloc(sizeof(t_tile));
	if (!game->food_list)
		ft_error("Error\n error allocating memory for game");
	game->food_list->visited = 0;
	game->food_list->x = 0;
	game->food_list->y = 0;
	game->food_list->next = 0;
}

t_game	*game_init(t_game *game)
{
	player_init(game);
	object_init(game);
	objectlist_init(game);
	foodlist_init(game);
	game->food_cnt = 0;
	game->house_cnt = 0;
	game->width = 1;
	game->height = 1;
	return (game);
}
