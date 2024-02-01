/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:15 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 21:15:35 by tpaim-yu         ###   ########.fr       */
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

// teste de loop para animações no BONUS
void ft_count_loop(void *param)
{
	t_game *game;
	int32_t time;

	game = (t_game *)param;
	time = (int)(mlx_get_time() * 10);
	if (game && (time % 20 == 0))
	{
		game->player_data[0]->img->enabled = 0;
		game->player_data[1]->img->enabled = 1;
	}
	else if (game && (time % 10 == 0))
	{
		game->player_data[0]->img->enabled = 1;
		game->player_data[1]->img->enabled = 0;
	}
}
// mlx_put_string;

void init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		ft_error();
	init_map_image(game);
	init_exit_image(game);
	init_collectible_image(game);
	init_player_img(game);
	game->lst_pos = '0';
	mlx_key_hook(game->mlx, &listen_moves, game);
	mlx_loop_hook(game->mlx, &ft_count_loop, game);
	mlx_loop(game->mlx);
}
