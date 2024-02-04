/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 06:24:52 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/03 06:24:52 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_enemies_img(t_game *game)
{
	int32_t	l;
	int32_t	c;

	game->enemy_data = insert_img_data(game, "./src_bonus/img/enemy.png");
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == 'X')
			{
				if (img_to_win(game, game->enemy_data, c, l))
					ft_error(game);
			}
			c++;
		}
		l++;
	}
}
