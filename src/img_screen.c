/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:39:24 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 19:16:46 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	img_to_win(t_game *game, mlx_image_t *img, int32_t c, int32_t l)
{
	if (mlx_image_to_window(game->mlx, img,
			WIDTH_TILE * c, HEIGHT_TILE * l) < 0)
		return (1);
	return (0);
}

void	upt_player_pos(t_game *game, int32_t l, int32_t c)
{
	game->player_pos_x = c;
	game->player_pos_y = l;
	ft_printf("Player pos: x-%d y-%d \n", c, l);
}

