/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:58:15 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 19:38:46 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	if_first_gnl_ok(char *gnl)
{
	int	len;

	len = 0;
	if (gnl)
		len = ft_strlen(gnl) - 1;
	if (!gnl || northest_wall_check(gnl, len) == -1)
		return (0);
	return (1);
}

char	*first_gnl(int src)
{
	char	*gnl;

	gnl = get_next_line(src);
	if (!if_first_gnl_ok(gnl))
	{
		free(gnl);
		ft_error("Error\nNorthest Border should be always 1");
		return (0);
	}
	return (gnl);
}

void	map_to_window(char *gnl, t_game *game, int src, int len)
{
	int	i;
	int	next_x;
	int	next_y;

	i = 0;
	next_x = 0;
	next_y = 0;
	while (gnl[i] != 0)
	{
		render_and_list(gnl[i], game, next_x, next_y);
		next_x += TILE_SIZE;
		i++;
		if (gnl[i] == '\n')
		{
			next_x = 0;
			next_y += TILE_SIZE;
			free(gnl);
			gnl = map_verify_and_gnl(src, len);
			i = 0;
		}
		if (gnl[i] == '\0')
			free(gnl);
	}
}

void	draw_ber(int src, t_game *game)
{
	char			*gnl;
	int				next_x;
	int				next_y;
	int				len;
	int				i;

	gnl = first_gnl(src);
	len = ft_strlen(gnl) - 1;
	next_x = 0;
	next_y = 0;
	game->map = ft_map_lstnew(*gnl, 0, 0);
	i = 0;
	map_to_window(gnl, game, src, len);
}
