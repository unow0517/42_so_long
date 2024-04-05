/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:47:46 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 19:40:40 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_tile	*ft_map_lstnew(char c, int x, int y)
{
	t_tile	*first_node;

	first_node = (t_tile *)malloc(sizeof(t_tile));
	if (!(first_node))
		return (0);
	if (c == '1')
		first_node->type = WALL;
	else
		first_node->type = GRASS;
	first_node->x = x;
	first_node->y = y;
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

	tile = ft_map_lstnew(c, 0, 0);
	if (c == '1')
		tile->type = 1;
	else
		tile->type = 0;
	tile->x = x;
	tile->y = y;
	ft_map_lstadd_back(list, tile);
}

int	img_to_window(mlx_t *mlx, mlx_texture_t *png, int x, int y)
{
	mlx_image_t		*img;

	img = mlx_texture_to_image(mlx, png);
	if (!img)
		return (-1);
	mlx_image_to_window(mlx, img, x, y);
	return (0);
}

// void	ft_lstdelone(t_list *lst)
// {
// 	if (lst != 0)
// 		del(lst->content);
// 	free (lst);
// }

