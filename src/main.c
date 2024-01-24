/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/23 21:31:22 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "MLX42/MLX42.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	delete_img_data(t_game *game, t_img_data *img_data)
{
	mlx_delete_image(game->mlx, img_data->img);
	mlx_delete_texture(img_data->texture);
	free(img_data);
}

// Print the window width and height.
// static void	ft_hook(void *param)
// {
// 	const mlx_t* mlx = param;

// 	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	is_direction(mlx_t *mlx, keys_t key1, keys_t key2)
{
	return (mlx_is_key_down(mlx, key1) || mlx_is_key_down(mlx, key2));
}

// int32_t	verify_char_pos(t_game *game)
// {
// 	if (game->character_data[1]->img->enabled)
// 		return (1);
// 	return (0);
// }

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (is_direction(game->mlx, MLX_KEY_A, MLX_KEY_LEFT))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		game->character_data[0]->img->instances[0].x -= WIDTH_TILE;
		game->character_data[1]->img->instances[0].x -= WIDTH_TILE;
		game->character_data[0]->img->enabled = 0;
		game->character_data[1]->img->enabled = 1;
	}
	if (is_direction(game->mlx, MLX_KEY_S, MLX_KEY_DOWN))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		game->character_data[0]->img->instances[0].y += HEIGHT_TILE;
		game->character_data[1]->img->instances[0].y += HEIGHT_TILE;
	}
	if (is_direction(game->mlx, MLX_KEY_D, MLX_KEY_RIGHT))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		game->character_data[0]->img->instances[0].x += WIDTH_TILE;
		game->character_data[1]->img->instances[0].x += WIDTH_TILE;
		game->character_data[0]->img->enabled = 1;
		game->character_data[1]->img->enabled = 0;
	}
	if (is_direction(game->mlx, MLX_KEY_W, MLX_KEY_UP))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		game->character_data[0]->img->instances[0].y -= HEIGHT_TILE;
		game->character_data[1]->img->instances[0].y -= HEIGHT_TILE;
	}
}

// teste de loop para animações no bonus
// void	ft_count_loop(void *i)
// {
// 	int32_t	*it;

// 	it = i;
// 	(*it)++;
// 	if(*it > 100)
// 		*it = 0;
// 	ft_printf("%d \n", *it);
// }

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

int32_t	main(void)
{
	t_game	game;
	// mlx_t	*mlx;
	int32_t			i;

	i = 0;
	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game.mlx)
		ft_error();
	game.character_data[0] = insert_img_data(&game, "./src/img/chopper_R.png");
	game.character_data[1] = insert_img_data(&game, "./src/img/chopper_L.png");
	game.wall_data = insert_img_data(&game, "./src/img/water.png");
	while (i < 10)
	{
		if (mlx_image_to_window(game.mlx, game.wall_data->img,
				WIDTH_TILE * i, HEIGHT_TILE * 0) < 0)
			ft_error();
		i++;
	}
	if ((mlx_image_to_window(game.mlx, game.character_data[0]->img,
				WIDTH_TILE * 4, HEIGHT_TILE * 0) < 0)
		|| mlx_image_to_window(game.mlx, game.character_data[1]->img,
			WIDTH_TILE * 4, HEIGHT_TILE * 0) < 0)
		ft_error();
	game.character_data[1]->img->enabled = 0;
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	// mlx_loop_hook(mlx, &ft_count_loop, &i);
	mlx_loop(game.mlx);
	delete_img_data(&game, game.character_data[0]);
	delete_img_data(&game, game.character_data[1]);
	delete_img_data(&game, game.wall_data);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
