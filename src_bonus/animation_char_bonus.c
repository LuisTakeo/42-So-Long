/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:42:01 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/02 19:42:01 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_count_loop(void *param)
{
	t_game	*game;
	int32_t	time;

	game = (t_game *)param;
	time = (int)(mlx_get_time() * 10);
	animate_player(game, time);
}

void	animate_player(t_game *game, int32_t time)
{
	int	x;
	int	y;

	x = 0;
	y = 2;
	if (game->player_data[1]->img->enabled
		|| game->player_data[3]->img->enabled)
	{
		x = 1;
		y = 3;
	}
	if ((time % 6 == 0))
	{
		game->player_data[x]->img->enabled = 0;
		game->player_data[y]->img->enabled = 1;
	}
	else if ((time % 3 == 0))
	{
		game->player_data[x]->img->enabled = 1;
		game->player_data[y]->img->enabled = 0;
	}
	animate_movement(game);
}

void	animate_movement(t_game *game)
{
	int32_t	step;

	step = 4;
	if (game->is_moving)
	{
		if (game->player_data[0]->img->instances[0].x > game->x_target
			|| game->player_data[0]->img->instances[0].y > game->y_target)
			step *= -1;
		if (game->player_data[0]->img->instances[0].x != game->x_target)
		{
			game->player_data[0]->img->instances[0].x += step;
			game->player_data[1]->img->instances[0].x += step;
			game->player_data[2]->img->instances[0].x += step;
			game->player_data[3]->img->instances[0].x += step;
		}
		else if (game->player_data[0]->img->instances[0].y != game->y_target)
		{
			game->player_data[0]->img->instances[0].y += step;
			game->player_data[1]->img->instances[0].y += step;
			game->player_data[2]->img->instances[0].y += step;
			game->player_data[3]->img->instances[0].y += step;
		}
		else
			game->is_moving = 0;
	}
}
