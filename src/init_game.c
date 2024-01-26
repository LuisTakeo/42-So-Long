/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:35:15 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/26 17:37:52 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img_data	*insert_img_data(t_game *game, char *img_path)
{
	t_img_data	*game_img;

	game_img = ft_calloc(sizeof (t_img_data), 1);
	if (!game_img)
		ft_error();
	game_img->texture = mlx_load_png(img_path);
	if (!(game_img->texture))
		ft_error();
	game_img->img = mlx_texture_to_image(game->mlx, game_img->texture);
	if (!game_img->img)
		ft_error();
	return (game_img);
}

void	init_map_image(t_game *game)
{
	int32_t	l;
	int32_t	c;

	game->wall_data = insert_img_data(game, "./src/img/water.png");
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == '1' && (mlx_image_to_window(game->mlx,
				game->wall_data->img, WIDTH_TILE * c, HEIGHT_TILE * l) < 0))
				ft_error();
			c++;
		}
		l++;
	}
}

void	init_player_img(t_game *game)
{
	int32_t	l;
	int32_t	c;

	game->character_data[0] = insert_img_data(game, "./src/img/chopper_R.png");
	game->character_data[1] = insert_img_data(game, "./src/img/chopper_L.png");
	game->character_data[0]->img->enabled = 0;
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == 'P' && ((mlx_image_to_window(game->mlx,
				game->character_data[0]->img, WIDTH_TILE * c,
				HEIGHT_TILE * l) < 0)
				|| (mlx_image_to_window(game->mlx, game->character_data[1]->img,
				WIDTH_TILE * c, HEIGHT_TILE * l) < 0)))
				ft_error();
			c++;
		}
		l++;
	}

}

void	init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game->mlx)
		ft_error();
	init_map_image(game);
	init_player_img(game);
}
