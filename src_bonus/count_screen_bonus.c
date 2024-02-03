/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:03:48 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/02 21:03:48 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_count(t_game *game)
{
	game->bg_count_data = insert_img_data(game, "./src_bonus/img/bg.png");
	if (mlx_image_to_window(
			game->mlx, game->bg_count_data->img, 0, 0) < 0)
		ft_error(game);
	game->text_img = mlx_put_string(game->mlx, "Steps:", 20, 22);
	upt_count_screen(game);
}

void	upt_count_screen(t_game *game)
{
	char	*str;

	if (game-> count_img)
		mlx_delete_image(game->mlx, game->count_img);
	str = ft_itoa(game->player_moves);
	game->count_img = mlx_put_string(game->mlx, str, 90, 20);
	mlx_resize_image(game->count_img, 14, 24);
	free(str);
}

