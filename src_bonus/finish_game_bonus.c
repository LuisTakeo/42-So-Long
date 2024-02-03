/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:16 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/01 19:32:35 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	finish_game(t_game *game)
{
	delete_img_data(game, game->player_data[0]);
	delete_img_data(game, game->player_data[1]);
	delete_img_data(game, game->player_data[2]);
	delete_img_data(game, game->player_data[3]);
	delete_img_data(game, game->wall_data);
	delete_img_data(game, game->floor_data);
	delete_img_data(game, game->exit_data);
	delete_img_data(game, game->bg_count_data);
	mlx_delete_image(game->mlx, game->count_img);
	mlx_delete_image(game->mlx, game->text_img);
	free_img_data(game, game->collect_data);
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

void	free_img_data(t_game *game, t_img_data **arr_img)
{
	int32_t	i;

	i = -1;
	while (arr_img[++i])
		delete_img_data(game, arr_img[i]);
	free (arr_img);
}

void	verify_end_game(t_game *game)
{
	if (game->lst_pos == 'E' && game->exit_active)
	{
		ft_printf("You win!\n");
		finish_game(game);
	}
}
