/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:15:06 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/04 04:38:01 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}
