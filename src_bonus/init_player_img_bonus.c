/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:49:08 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/02 19:49:08 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_player_img(t_game *game)
{
	int32_t	l;
	int32_t	c;

	init_player_frames (game);
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == 'P')
			{
				put_player_to_win(game, c, l);
				upt_player_pos(game, l, c);
				return ;
			}
			c++;
		}
		l++;
	}
}

void	init_player_frames(t_game *game)
{
	game->player_data[0] = insert_img_data(
			game, "./src_bonus/img/chopper_R.png");
	game->player_data[1] = insert_img_data(
			game, "./src_bonus/img/chopper_L.png");
	game->player_data[2] = insert_img_data(
			game, "./src_bonus/img/chopper_R_open.png");
	game->player_data[3] = insert_img_data(
			game, "./src_bonus/img/chopper_L_open.png");
	game->player_data[0]->img->enabled = 0;
	game->player_data[2]->img->enabled = 0;
	game->player_data[3]->img->enabled = 0;
}

void	put_player_to_win(t_game *game, int32_t c, int32_t l)
{
	if (img_to_win(game, game->player_data[0], c, l)
		|| img_to_win(game, game->player_data[1], c, l)
		|| img_to_win(game, game->player_data[2], c, l)
		|| img_to_win(game, game->player_data[3], c, l))
		ft_error();
}
