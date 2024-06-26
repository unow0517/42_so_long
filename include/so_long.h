/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:31:22 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 22:45:45 by yowoo            ###   ########.fr       */
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
# define TILE_SIZE 128

typedef struct s_player
{
	int				x;
	int				y;
	int				movements;
	int				collect_cnt;
}	t_player;

enum e_tiletype
{
	WALL,
	GRASS
};

typedef struct s_tile
{
	enum e_tiletype	type;
	int				visited;
	int				x;
	int				y;
	struct s_tile	*next;
}	t_tile;

typedef struct s_object
{
	int				x;
	int				y;
}	t_object;

typedef struct s_objectlist
{
	int				x;
	int				y;
	struct s_water	*next;
}	t_objectlist;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_tile			*map;
	t_object		*food;
	t_objectlist	*grass;
	t_objectlist	*water;
	t_object		*house;
	t_tile			*grass_list;
	t_tile			*food_list;
	int				player_cnt;
	int				food_cnt;
	int				house_cnt;
	int				width;
	int				height;
	mlx_texture_t	*player_png;
	mlx_texture_t	*food_png;
	mlx_texture_t	*house_png;
	mlx_texture_t	*grass_png;
	mlx_texture_t	*water_png;

}	t_game;

//SO_LONG.C
void		ft_error(char *str);
int			iswall(t_tile *map, int x, int y);
//static void	get_map_size(char **argv, t_game *game);
//static void	if_not_game(t_game *game)
//int32_t		main(int argc, char **argv)

//GAME_INIT.C
//static void	player_init(t_game *game)
//static void	object_init(t_game *game)
//static void	objectlist_init(t_game *game)
//static void	foodlist_init(t_game *game)
t_game		*game_init(t_game *game);

//RENDER.C
void		add_object(t_game *game, int x, int y, char c);
void		render_tile(t_game *game, char c, int x, int y);
void		render_and_list(char c, t_game *game, int next_x, int next_y);
void		load_pngs(t_game *game);

//DRAW_BER.C
int			if_first_gnl_ok(char *gnl);
char		*first_gnl(int src);
void		map_to_window(char *gnl, t_game *game, int src, int len);
void		draw_ber(int src, t_game *game);

//MAP_FUNCTIONS.C
t_tile		*ft_map_lstnew(char c, int x, int y);
void		ft_map_lstadd_back(t_tile **lst, t_tile *new);
t_tile		*ft_map_lstlast(t_tile *lst);
void		tile_to_map_list(char c, t_tile **list, int x, int y);
int			img_to_window(mlx_t *mlx, mlx_texture_t *png, int x, int y);

//MOVES.C
//static void	move(t_game *game, int next_x, int next_y);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

//MAP_VERIFY.C
// static int	mid_wall_check(char *str, int len);
int			northest_wall_check(char *str, int len);
//static int	end_wall_check(char *str, int len);
//static int	map_verify(char *str, int len);
char		*map_verify_and_gnl(int src, int len);

//CHECK_TILE.C
// static int	is_coord_grass(int x, int y, t_tile *map);
// static void	put_in_grass_list(int x, int y, t_tile *grass_list);
void		flood_fill(int x, int y, t_game *game);

//ERROR_CHECK.C
int			is_in_list(int x, int y, t_tile *grass_list);
t_tile		*find_tile_in_list(int x, int y, t_tile *list);
//static int	is_p_c_e_in_one_map(t_game *game);
void		error_check(t_game *game);

//MLX_HOOKS.C
// static void	my_keyhook(mlx_key_data_t keydata, void *param);
// static void	finish_game(void *param);
void		mlx_hooks(t_game *game);

#endif