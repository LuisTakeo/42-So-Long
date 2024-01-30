/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:39:24 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/30 14:20:50 by tpaim-yu         ###   ########.fr       */
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

void	init_map_image(t_game *game)
{
	int32_t	l;
	int32_t	c;
	int32_t	is_invalid;

	is_invalid = 0;
	game->wall_data = insert_img_data(game, "./src/img/water.png");
	game->floor_data = insert_img_data(game, "./src/img/floor.png");
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == '1')
				is_invalid += img_to_win(game, game->wall_data->img, c, l);
			if (ft_strchr("0PCE", game->map[l][c]))
				is_invalid += img_to_win(game, game->floor_data->img, c, l);
			if (is_invalid)
				ft_error();
			c++;
		}
		l++;
	}
}

void	upt_player_pos(t_game *game, int32_t l, int32_t c)
{
	game->player_pos_x = c;
	game->player_pos_y = l;
	ft_printf("Player pos: x-%d y-%d \n", c, l);
}

void	init_exit_image(t_game *game)
{
	int32_t	l;
	int32_t	c;

	game->exit_data = insert_img_data(game, "./src/img/exit.png");
	game->exit_data->img->enabled = 0;
	game->exit_active = 0;
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == 'E')
			{
				if (img_to_win(game, game->exit_data->img, c, l))
					ft_error();
				return ;
			}
			c++;
		}
		l++;
	}

}

void	init_player_img(t_game *game)
{
	int32_t	l;
	int32_t	c;

	game->player_data[0] = insert_img_data(game, "./src/img/chopper_R.png");
	game->player_data[1] = insert_img_data(game, "./src/img/chopper_L.png");
	game->player_data[0]->img->enabled = 0;
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == 'P')
			{
				if (img_to_win(game, game->player_data[0]->img, c, l)
					|| img_to_win(game, game->player_data[1]->img, c, l))
					ft_error();
				upt_player_pos(game, l, c);
				return ;
			}
			c++;
		}
		l++;
	}
}
