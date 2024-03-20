/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:47:46 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/20 12:49:04 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_tile	*ft_map_lstnew(char c)
{
	t_tile	*first_node;

	first_node = (t_tile *)malloc(sizeof(t_tile));
	if (!(first_node))
		return (0);
	if (c == '1')
		first_node->type = WALL;
	if (c == '0')
		first_node->type = GRASS;
	first_node->x = 0;
	first_node->y = 0;
	first_node->next = 0;
	return (first_node);
}

void	ft_map_lstadd_back(t_tile **lst, t_tile *new)
{
	if (!*lst || !lst)
	{
		*lst = new;
	}
	else
	{
		ft_map_lstlast(*lst)->next = new;
	}
}

t_tile	*ft_map_lstlast(t_tile *lst)
{
	t_tile	*result;

	if (!lst)
		return (0);
	result = lst;
	while (result->next != 0)
		result = result->next;
	return (result);
}

void	tile_to_map_list(char c, t_tile **list, int x, int y)
{
	t_tile			*tile;

	tile = ft_map_lstnew(c);
	if (c == '1')
		tile->type = '1';
	else
		tile->type = '0';
	tile->x = x;
	tile->y = y;
	ft_map_lstadd_back(list, tile);
}

int	path_to_window(mlx_t *mlx, char *path, int x, int y)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(mlx, texture);
	if (!texture || !img)
		return (-1);
	mlx_image_to_window(mlx, img, x, y);
	return (0);
}
