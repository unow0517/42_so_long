/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:58:15 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/04 11:34:13 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	add_object(t_game *game, int x, int y, char c)
{
	if (c == 'P')
	{
		img_to_window(game->mlx, game->player->png, x, y);
		game->player->x = x;
		game->player->y = y;
		game->player->cnt++;
	}
	else if (c == 'C')
	{
		img_to_window(game->mlx, game->food->png, x, y);
		game->food->x = x;
		game->food->y = y;
		game->food->cnt++;
	}
	else if (c == 'E')
	{
		img_to_window(game->mlx, game->house->png, x, y);
		game->house->x = x;
		game->house->y = y;
		game->house->cnt++;
	}
}

static void	render_tile(t_game *game, char c, int x, int y)
{
	if (c == '1')
	{
		img_to_window(game->mlx, game->water->png, x, y);
	}
	else
	{
		img_to_window(game->mlx, game->grass->png, x, y);
		add_object(game, x, y, c);
	}
}

static void	render_and_list(char c, t_game *game, int next_x, int next_y)
{
	// printf("HERE!%s\n", gnl);
	tile_to_map_list(c, &game->map, next_x, next_y);
	render_tile(game, c, next_x, next_y);
}


int	if_gnl_ok(char *gnl)
{
	int	len;

	len = 0;
	if (gnl)
		len = ft_strlen(gnl) - 1;
	if (!gnl || northest_wall_check(gnl, len) == -1)
		return (0);
	return (1);
}

int	draw_ber(int src, t_game *game)
{
	char			*gnl;
	int				next_x;
	int				next_y;
	int				len;
	int				i;

	gnl = get_next_line(src);
	if (!if_gnl_ok(gnl))
	{
		free(gnl);
		return (-1);
	}
	len = ft_strlen(gnl) - 1;
	next_x = 0;
	next_y = 0;
	game->map = ft_map_lstnew(*gnl, 0, 0);
	i = 0;
	while (gnl[i] != 0)
	{
		render_and_list(gnl[i], game, next_x, next_y);
		next_x += 128;
		i++;
		if (gnl[i] == '\n')
		{
			next_x = 0;
			next_y += 128;
			free(gnl);
			gnl = map_verify_and_gnl(src, len);
			i = 0;
		}
		if (gnl[i] == '\0')
			free(gnl);
	}
	return (0);
}
