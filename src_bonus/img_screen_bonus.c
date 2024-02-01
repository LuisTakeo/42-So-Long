/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_screen_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:39:24 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/01 19:33:16 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int32_t	img_to_win(t_game *game, t_img_data *src, int32_t c, int32_t l)
{
	if (mlx_image_to_window(game->mlx, src->img,
			WIDTH_TILE * c, HEIGHT_TILE * l) < 0)
		return (1);
	src->x = c;
	src->y = l;
	return (0);
}

void	upt_player_pos(t_game *game, int32_t l, int32_t c)
{
	game->player_pos_x = c;
	game->player_pos_y = l;
	ft_printf("Player pos: x-%d y-%d \n", c, l);
}

void	upt_collectable(t_game *game, int32_t y, int32_t x)
{
	int	l;

	l = -1;
	while (game->collect_data[++l])
	{
		if (game->collect_data[l]->y == y
			&& game->collect_data[l]->x == x)
			game->collect_data[l]->img->enabled = 0;
	}
}

