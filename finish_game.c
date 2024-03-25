/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:13:38 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/25 10:40:56 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	finish_game(void *param)
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
			exit(0);
}
