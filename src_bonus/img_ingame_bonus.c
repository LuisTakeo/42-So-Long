/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ingame_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:20:08 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/04 04:59:47 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	move_player(t_game *game, char pos, char operator)
{
	int32_t	x;

	x = WIDTH_TILE;
	if (operator == '-')
		x *= -1;
	if (pos == 'x')
	{
		game->player_data[0]->img->instances[0].x += x;
		game->player_data[1]->img->instances[0].x += x;
		game->player_data[2]->img->instances[0].x += x;
		game->player_data[3]->img->instances[0].x += x;
	}
	if (pos == 'y')
	{
		game->player_data[0]->img->instances[0].y += x;
		game->player_data[1]->img->instances[0].y += x;
		game->player_data[2]->img->instances[0].y += x;
		game->player_data[3]->img->instances[0].y += x;
	}
	game->player_moves++;
	upt_count_screen(game);
}

void	upt_img_side(t_img_data **player_data, char side)
{
	if (side == '>')
	{
		player_data[0]->img->enabled = 0;
		player_data[1]->img->enabled = 1;
		player_data[2]->img->enabled = 0;
		player_data[3]->img->enabled = 0;
	}
	if (side == '<')
	{
		player_data[0]->img->enabled = 1;
		player_data[1]->img->enabled = 0;
		player_data[2]->img->enabled = 0;
		player_data[3]->img->enabled = 0;
	}
}
