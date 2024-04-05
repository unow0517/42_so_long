/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:16:39 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 20:26:38 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	is_in_list(int x, int y, t_tile *grass_list)
{
	t_tile	*ptr;

	ptr = grass_list;
	if (!ptr)
		return (0);
	while (ptr)
	{
		if (ptr->x == x && ptr->y == y)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

t_tile	*find_tile_in_list(int x, int y, t_tile *list)
{
	t_tile	*ptr;

	ptr = list;
	if (!ptr)
		return (0);
	while (ptr)
	{
		if (ptr->x == x && ptr->y == y)
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}

static int	is_p_c_e_in_one_map(t_game *game)
{
	t_player	*player;
	int			p;
	int			f;
	int			h;

	game->grass_list = malloc(sizeof(t_tile));
	game->grass_list->x = 0;
	game->grass_list->y = 0;
	game->grass_list->next = 0;
	player = game->player;
	flood_fill(player->x, player->y, game);
	p = is_in_list(player->x, player->y, game->grass_list);
	f = is_in_list(game->food->x, game->food->y, game->grass_list);
	h = is_in_list(game->house->x, game->house->y, game->grass_list);
	if (p + f + h != 3)
		ft_error("Error\nPlayer, Food, House should be connected on the map!");
	return (0);
}

void	error_check(t_game *game)
{
	is_p_c_e_in_one_map(game);
	if (game->player_cnt * game->house_cnt != 1 || game->food_cnt < 1)
		ft_error("Error\n1 Player, 1 or more Foods, 1 House must be on the map!");
}
