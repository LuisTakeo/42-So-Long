/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:03:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/01 20:01:46 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH_TILE 64
# define HEIGHT_TILE 64
# define WIDTH 1900
# define HEIGHT 600

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/gnl/includes/get_next_line.h"
# include "../lib/libft/ft_printf/includes/ft_printf.h"
# include <fcntl.h>

typedef struct s_image_data
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int32_t			x;
	int32_t			y;
}	t_img_data;

typedef struct s_valid_map
{
	int32_t	last_col;
	int32_t	last_line;
	int32_t	ply_occ;
	int32_t	collectible_occ;
	int32_t	exit_occ;
}	t_valid_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_img_data	*wall_data;
	t_img_data	*floor_data;
	t_img_data	*exit_data;
	t_img_data	*player_data[2];
	t_img_data	**collect_data;
	int32_t		collectibles;
	int32_t		player_pos_x;
	int32_t		player_pos_y;
	int32_t		player_moves;
	int32_t		exit_active;
	char		**map;
	char		lst_pos;
	int32_t		max_width_tiles;
	int32_t		max_height_tiles;
}	t_game;

// validations pre-game
void		is_valid_entry(char *entry, char *extension);
void		validate_map(char *path);
void		verify_min_size(char **map);
int			count_occ(char *str, char c);
void		verify_rectangle(char **map, t_valid_map *t_map);
void		verify_char_valid(char **map);
void		init_map_validator(t_valid_map *map);
void		verify_min_char(char **map, t_valid_map *t_map);
void		verify_walls(char **map, t_valid_map *t_map);
void		verify_pathway(char **map);
void		flood_fill(char **map, int32_t l, int32_t c);
void		verify_map_flood(char **map);
void		count_colletibles(t_game *game);
// generate maps functions
char		**generate_map(char *file);
t_list		*read_file_to_list(char *file);
char		**read_list_to_arr(t_list *str_list);
// key listeners and movements functions
void		listen_moves(mlx_key_data_t keydata, void *param);
void		move_player(t_game *game, char pos, char operator);
// validations in-game
int			is_invalid_move(t_game *game, char direction, char op);
int32_t		is_direction(mlx_key_data_t keydata, keys_t key1, keys_t key2);
void		verify_end_game(t_game *game);
// init game
void		init_values(t_game *game);
void		init_game(t_game *game);
void		init_player_img(t_game *game);
void		init_map_image(t_game *game);
void		init_exit_image(t_game *game);
void		upt_player_pos(t_game *game, int32_t l, int32_t c);
void		init_collectible_image(t_game *game);
void		alloc_collectibles(t_game *game);
// map functions
void		upt_map_player(t_game *game, int32_t y, int32_t x);
// images functions
t_img_data	*insert_img_data(t_game *game, char *img_path);
void		upt_img_screen(t_game *game, char direction, char op);
void		upt_img_side(t_img_data **player_data, char side);
int32_t		img_to_win(t_game *game, t_img_data *src, int32_t c, int32_t l);
void		upt_exit_screen(t_game *game);
void		upt_collectable(t_game *game, int32_t y, int32_t x);
// finish game
void		delete_img_data(t_game *game, t_img_data *img_data);
void		free_map(char **map);
void		free_img_data(t_game *game, t_img_data **arr_img);
void		finish_game(t_game *game);
// error functions
void		ft_error(void);

#endif
