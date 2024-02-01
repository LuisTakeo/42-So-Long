/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:16 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 17:36:33 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish_game(t_game *game)
{
	delete_img_data(game, game->player_data[0]);
	delete_img_data(game, game->player_data[1]);
	delete_img_data(game, game->wall_data);
	delete_img_data(game, game->floor_data);
	delete_img_data(game, game->exit_data);
	free_map(game->map);
	mlx_terminate(game->mlx);
	exit(MLX_SUCCESS);
}

void	free_map(char **map)
{
	int32_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}

void	verify_end_game(t_game *game)
{
	if (game->lst_pos == 'E' && game->exit_active)
		finish_game(game);
}
