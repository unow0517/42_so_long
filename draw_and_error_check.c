/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_error_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:16:39 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/22 23:21:35 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	draw_and_error_check(t_game *game)
{
	is_p_c_e_in_one_map(game);
	if (game->player->cnt * game->food->cnt * game->house->cnt != 1)
		ft_error("Error\nOnly 1 Player, 1 Food, 1 House must be on the map!");
}
