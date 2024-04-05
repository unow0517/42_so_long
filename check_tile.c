/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:08:43 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 16:28:22 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"



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
		return ;
	if (is_in_list(x, y, game->grass_list))
		return ;
	put_in_grass_list(x, y, game->grass_list);
	flood_fill(x - 128, y, game);
	flood_fill(x + 128, y, game);
	flood_fill(x, y - 128, game);
	flood_fill(x, y + 128, game);
}
