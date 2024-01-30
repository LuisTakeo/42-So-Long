/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:27:01 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/29 22:25:05 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	is_direction(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1 || keydata.key == key2)
		&& keydata.action == MLX_PRESS);
}

void	upt_img_side(t_img_data **player_data, char side)
{
	if (side == '>')
	{
		player_data[0]->img->enabled = 0;
		player_data[1]->img->enabled = 1;
	}
	if (side == '<')
	{
		player_data[0]->img->enabled = 1;
		player_data[1]->img->enabled = 0;
	}
}

void	upt_map_player(t_game *game, int32_t y, int32_t x)
{
	int32_t	old_y;
	int32_t	old_x;
	char	last_temp;

	old_y = game->player_pos_y;
	old_x = game->player_pos_x;
	last_temp = game->lst_pos;
	game->lst_pos = game->map[y][x];
	game->map[y][x] = 'P';
	if (ft_strchr("0C", last_temp))
		game->map[old_y][old_x] = '0';
	else
		game->map[old_y][old_x] = last_temp;
	ft_printf("Line %d: %s", y, game->map[y]);
}

void	verify_collectible(t_game *game, int32_t y, int32_t x)
{
	if (game->map[y][x] == 'C')
		game->collectibles -= 1;
	if (game->collectibles == 0)
		game->exit_active = 1;
	ft_printf("Coletáveis: %d\n", game->collectibles);
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

void	verify_end_game(t_game *game)
{
	if (game->lst_pos == 'E' && game->exit_active)
		finish_game(game);
}

void	upt_img_screen(t_game *game, char direction, char op)
{
	if (is_invalid_move(game, direction, op))
		return ;
	if (direction == 'x')
	{
		if (op == '-')
			upt_img_side(game->player_data, '>');
		if (op == '+')
			upt_img_side(game->player_data, '<');
	}
	move_player(game, direction, op);
	verify_end_game(game);
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
		exit(0);
}

void	move_player(t_game *game, char pos, char operator)
{
	if (pos == 'x' && operator == '+')
	{
		game->player_data[0]->img->instances[0].x += WIDTH_TILE;
		game->player_data[1]->img->instances[0].x += WIDTH_TILE;
	}
	if (pos == 'x' && operator == '-')
	{
		game->player_data[0]->img->instances[0].x -= WIDTH_TILE;
		game->player_data[1]->img->instances[0].x -= WIDTH_TILE;
	}
	if (pos == 'y' && operator == '+')
	{
		game->player_data[0]->img->instances[0].y += WIDTH_TILE;
		game->player_data[1]->img->instances[0].y += WIDTH_TILE;
	}
	if (pos == 'y' && operator == '-')
	{
		game->player_data[0]->img->instances[0].y -= WIDTH_TILE;
		game->player_data[1]->img->instances[0].y -= WIDTH_TILE;
	}
	game->player_moves++;
	ft_printf("Steps: %d\n", game->player_moves);
}
