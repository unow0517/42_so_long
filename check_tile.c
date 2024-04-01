/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:08:43 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/25 13:00:11 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	is_in_list(int x, int y, t_tile *grass_list)
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

static int	is_coord_grass(int x, int y, t_tile *map)
{
	t_tile	*ptr;


	ptr = map;
	while (ptr)
	{
		if (ptr->x == x && ptr->y == y && ptr->type == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static void	put_in_grass_list(int x, int y, t_tile *grass_list)
{
	t_tile	**listptr;

	listptr = &grass_list;
	if (x < 0 || y < 0)
		return ;
	if (!grass_list)
		grass_list = ft_map_lstnew('0', x, y);
	ft_map_lstadd_back(listptr, ft_map_lstnew('0', x, y));
}

void	flood_fill(int x, int y, t_game *game)
{
	if (!(is_coord_grass(x, y, game->map)))
	{
		return ;
	}
	if (is_in_list(x, y, game->grass_list))
	{
		return ;
	}
	put_in_grass_list(x, y, game->grass_list);
	flood_fill(x - 128, y, game);
	flood_fill(x + 128, y, game);
	flood_fill(x, y - 128, game);
	flood_fill(x, y + 128, game);
}

int	is_p_c_e_in_one_map(t_game *game)
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
