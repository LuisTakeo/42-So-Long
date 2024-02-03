/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:15 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/03 07:38:06 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img_data	*insert_img_data(t_game *game, char *img_path)
{
	t_img_data	*game_img;

	game_img = ft_calloc(sizeof(t_img_data), 1);
	if (!game_img)
		ft_error();
	game_img->texture = mlx_load_png(img_path);
	if (!(game_img->texture))
		ft_error();
	game_img->img = mlx_texture_to_image(game->mlx, game_img->texture);
	if (!game_img->img)
		ft_error();
	game_img->x = 0;
	game_img->y = 0;
	return (game_img);
}

void	init_values(t_game *game)
{
	game->mlx = NULL;
	game->wall_data = NULL;
	game->floor_data = NULL;
	game->collect_data = NULL;
	game->exit_data = NULL;
	game->player_data[0] = NULL;
	game->player_data[1] = NULL;
	game->collect_data = NULL;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->player_moves = 0;
	game->collectibles = 0;
	game->exit_active = 0;
	game->map = NULL;
	game->lst_pos = 0;
	game->max_width_tiles = 0;
	game->max_height_tiles = 0;
}

void	count_map_size(t_game *game)
{
	int32_t	l;
	int32_t	c;

	l = 0;
	c = 0;
	while (game->map[l])
		l++;
	while (!ft_strchr("\r\n", game->map[0][c]))
		c++;
	game->max_width_tiles = c;
	game->max_height_tiles = l;
}

void	put_floor_image(t_game *game)
{
	int32_t	l;
	int32_t	c;
	int32_t	is_invalid;

	is_invalid = 0;
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (ft_strchr("0PCE", game->map[l][c]))
				is_invalid += img_to_win(game, game->floor_data, c, l);
			if (is_invalid)
				ft_error();
			c++;
		}
		l++;
	}
}

void	init_game(t_game *game)
{
	count_map_size(game);
	game->mlx = mlx_init(WIDTH_TILE * game->max_width_tiles,
			game->max_height_tiles * HEIGHT_TILE, "so_long", true);
	if (!game->mlx)
		ft_error();
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_map_image(game);
	init_exit_image(game);
	init_collectible_image(game);
	init_player_img(game);
	game->lst_pos = '0';
	mlx_key_hook(game->mlx, &listen_moves, game);
	mlx_loop(game->mlx);
}
