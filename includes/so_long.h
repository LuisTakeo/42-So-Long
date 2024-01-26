/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:03:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/26 19:32:35 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH_TILE 128
# define HEIGHT_TILE 128
# define WIDTH 1600
# define HEIGHT 800

# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/gnl/includes/get_next_line.h"
# include "../lib/libft/ft_printf/includes/ft_printf.h"
# include <fcntl.h>

typedef struct s_image_data
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}	t_img_data;

typedef struct s_game
{
	mlx_t		*mlx;
	t_img_data	*wall_data;
	t_img_data	*floor_data;
	t_img_data	*collectible_data;
	t_img_data	*character_data[2];
	int32_t		character_pos_x;
	int32_t		character_pos_y;
	int32_t		character_moves;
	char		**map;
	int32_t		max_width_tiles;
	int32_t		max_height_tiles;
}	t_game;

// generate maps functions
char		**generate_map(char *file);
t_list		*read_file_to_list(char *file);
char		**read_list_to_arr(t_list *str_list);
// key listeners and movements functions
void		listen_moves(mlx_key_data_t keydata, void *param);
int32_t		is_direction(mlx_key_data_t keydata, keys_t key1, keys_t key2);
void		move_character(t_game *game, char pos, char operator);
// init game
void		init_game(t_game *game);
void		init_player_img(t_game *game);
void		init_map_image(t_game *game);
// images functions
t_img_data	*insert_img_data(t_game *game, char *img_path);
void		delete_img_data(t_game *game, t_img_data *img_data);
int32_t		img_to_win(t_game *game, mlx_image_t *img, int32_t c, int32_t l);
// error functions
void		ft_error(void);

#endif
