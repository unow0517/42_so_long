/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:31:22 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/25 11:47:26 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42.h"
# include "../GET_NEXT_LINE/get_next_line.h"
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# define PATH_GRASS "./img/grass_128.png"
# define PATH_WATER "./img/water_128.png"
# define PATH_SHIBA "./img/shiba_128.png"
# define PATH_HOUSE "./img/house_128.png"
# define PATH_FOOD "./img/food_128.png"

typedef struct s_player
{
	int			x;
	int			y;
	int			movements;
	int			cnt;
	int			if_collect;
}	t_player;

enum e_tiletype
{
	WALL,
	GRASS
};

typedef struct s_tile
{
	enum e_tiletype	type;
	int				x;
	int				y;
	struct s_tile	*next;
}	t_tile;

typedef struct s_food
{
	int	x;
	int	y;
	int	cnt;
}	t_food;

typedef struct s_house
{
	int	x;
	int	y;
	int	cnt;
}	t_house;

typedef struct s_grass
{
	int				x;
	int				y;
	struct s_grass	*next;
}	t_grass;

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	*player;
	t_tile		*map;
	t_food		*food;
	t_house		*house;
	t_tile		*grass_list;
	int			width;
	int			height;
}	t_game;

//SO_LONG.C
void	ft_error(char *str);
int		iswall(t_tile *map, int x, int y);
// static void	my_keyhook(mlx_key_data_t keydata, void *param);
char	*get_map_size(char **argv, t_game *game);
t_game	*game_init(t_game *game);
// int32_t	main(int argc, char **argv);

//GAME_INIT.C
t_game	*game_init(t_game *game);

//DRAW_BER.C
// static void	add_object(t_game *game, int x, int y, char c);
// static void	render_tile(t_game *game, char c, int x, int y);
// static void	render_and_list(arguments...);
int		if_gnl_ok(char *gnl);
int		draw_ber(int src, t_game *game);

//MAP_FUNCTIONS.C
t_tile	*ft_map_lstnew(char c, int x, int y);
void	ft_map_lstadd_back(t_tile **lst, t_tile *new);
t_tile	*ft_map_lstlast(t_tile *lst);
void	tile_to_map_list(char c, t_tile **list, int x, int y);
int		path_to_window(mlx_t *mlx, char *path, int x, int y);

//MOVES.C
//static void	move(t_game *game, int next_x, int next_y);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//MAP_VERIFY.C
// static int	mid_wall_check(char *str, int len);
int		end_wall_check(char *str, int len);
int		map_verify(char *str, char *laststr, int len);
char	*map_verify_and_gnl(int src, char *str, int len);

//CHECK_TILE.C
// static int	is_in_list(int x, int y, t_tile *grass_list);
// static int	is_coord_grass(int x, int y, t_tile *map);
// static void	put_in_grass_list(int x, int y, t_tile *grass_list);
void	flood_fill(int x, int y, t_game *game);
int		is_p_c_e_in_one_map(t_game *game);

//DRAW_AND_ERROR_CHECK.C
void	error_check(t_game *game);

//FINISH_GAME.C
void	finish_game(void *param);
void	finish_game1(t_game *game);

#endif