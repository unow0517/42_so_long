/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:58:15 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/22 23:09:58 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	render_and_list(char *gnl, t_game *game, int next_x, int next_y)
{
	tile_to_map_list(*gnl, &game->map, next_x, next_y);
	render_tile(game, *gnl, next_x, next_y);

}

int	draw_ber(int src, t_game *game)
{
	char			*gnl;
	int				next_x;
	int				next_y;
	int				len;

	gnl = get_next_line(src);
	if (gnl)
		len = ft_strlen(gnl) - 1;
	if (!gnl || end_wall_check(gnl, len) == -1)
		return (-1);
	next_y = 0;
	game->map = ft_map_lstnew(*gnl, 0, 0);
	while (*gnl != 0)
	{
		render_and_list(gnl, game, next_x, next_y);
		next_x += 128;
		gnl++;
		if (*gnl == '\n')
		{
			next_x = 0;
			next_y += 128;
			gnl = map_verify_and_gnl(src, gnl, len);
		}
	}
	return (0);
}
