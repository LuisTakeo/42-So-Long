/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ingame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:20:08 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/02 20:39:35 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
