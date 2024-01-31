/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:27:01 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/30 14:23:43 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	is_direction(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1 || keydata.key == key2)
		&& keydata.action == MLX_PRESS);
}

void	verify_collectible(t_game *game, int32_t y, int32_t x)
{
	if (game->map[y][x] == 'C')
		game->collectibles -= 1;
	if (game->collectibles == 0)
		game->exit_active = 1;
}

void	upt_exit_screen(t_game *game)
{
	if (game->exit_active)
		game->exit_data->img->enabled = 1;
}

int	is_invalid_move(t_game *game, char direction, char op)
{
	int32_t	x;
	int32_t	y;
	int32_t	sum;

	sum = 1;
	x = game->player_pos_x;
	y = game->player_pos_y;
	if (op == '-')
		sum = -1;
	if (direction == 'x')
		x += sum;
	if (direction == 'y')
		y += sum;
	if (game->map[y][x] == '1')
		return (1);
	verify_collectible(game, y, x);
	upt_exit_screen(game);
	upt_map_player(game, y, x);
	upt_player_pos(game, y, x);
	return (0);
}

void	listen_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (is_direction(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		upt_img_screen(game, 'x', '-');
	if (is_direction(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		upt_img_screen(game, 'y', '+');
	if (is_direction(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		upt_img_screen(game, 'x', '+');
	if (is_direction(keydata, MLX_KEY_W, MLX_KEY_UP))
		upt_img_screen(game, 'y', '-');
	if (is_direction(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
		finish_game(game);
}
