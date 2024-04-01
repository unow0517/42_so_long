/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:16 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/01 12:32:28 by yowoo            ###   ########.fr       */
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
	game->player->cnt = 0;
	game->player->movements = 0;
	game->player->if_collect = 0;
	game->food->cnt = 0;
	game->house->cnt = 0;
	game->width = 1;
	game->height = 1;
	return (game);
}
