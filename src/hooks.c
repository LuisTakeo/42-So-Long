/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:27:01 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/26 21:06:19 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	is_direction(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1 || keydata.key == key2)
		&& keydata.action == MLX_PRESS);
}

void	listen_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (is_direction(keydata, MLX_KEY_A, MLX_KEY_LEFT))
	{
		game->character_data[0]->img->enabled = 0;
		game->character_data[1]->img->enabled = 1;
		move_character(game, 'x', '-');
	}
	if (is_direction(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		move_character(game, 'y', '+');
	if (is_direction(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
	{
		game->character_data[0]->img->enabled = 1;
		game->character_data[1]->img->enabled = 0;
		move_character(game, 'x', '+');
	}
	if (is_direction(keydata, MLX_KEY_W, MLX_KEY_UP))
		move_character(game, 'y', '-');
	if (is_direction(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
		exit(0);
}

void	move_character(t_game *game, char pos, char operator)
{
	if (pos == 'x' && operator == '+')
	{
		game->character_data[0]->img->instances[0].x += WIDTH_TILE;
		game->character_data[1]->img->instances[0].x += WIDTH_TILE;
	}
	if (pos == 'x' && operator == '-')
	{
		game->character_data[0]->img->instances[0].x -= WIDTH_TILE;
		game->character_data[1]->img->instances[0].x -= WIDTH_TILE;
	}
	if (pos == 'y' && operator == '+')
	{
		game->character_data[0]->img->instances[0].y += WIDTH_TILE;
		game->character_data[1]->img->instances[0].y += WIDTH_TILE;
	}
	if (pos == 'y' && operator == '-')
	{
		game->character_data[0]->img->instances[0].y -= WIDTH_TILE;
		game->character_data[1]->img->instances[0].y -= WIDTH_TILE;
	}
	game->character_moves++;
	ft_printf("Steps: %d\n", game->character_moves);
}
