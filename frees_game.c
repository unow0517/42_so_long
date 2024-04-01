/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:00:52 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/01 13:20:35 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	free_list(t_tile *head)
{
	t_tile	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	frees_game(t_game *game)
{
	free_list(game->map);
	free_list(game->grass_list);
	free(game->player);
	free(game->food);
	free(game->house);
	free(game->grass);
	free(game->water);
	free(game->mlx->window);
	free(game->mlx->context);
	free(game->mlx);
	free(game);
	printf("hello");
}
