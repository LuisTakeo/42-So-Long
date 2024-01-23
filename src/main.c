/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/23 19:11:12 by tpaim-yu         ###   ########.fr       */
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

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int32_t	i;
	int32_t move_div;
	int32_t move_timing;

	i = 0;
	move_div = 128;
	move_timing = WIDTH_TILE / move_div;
	game = (t_game *)param;
	if (is_direction(game->mlx, MLX_KEY_A, MLX_KEY_LEFT))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		while (i < move_div)
		{
			game->character_data->img->instances[0].x -= move_timing;
			i++;
		}

		// game->character_data->img->instances[0].x -= 128;
	}
	if (is_direction(game->mlx, MLX_KEY_S, MLX_KEY_DOWN))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		while (i < move_div)
		{
			game->character_data->img->instances[0].y += move_timing;
			i++;
		}
		// game->character_data->img->instances[0].y += 128;
	}
	if (is_direction(game->mlx, MLX_KEY_D, MLX_KEY_RIGHT))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		while (i < move_div)
		{
			game->character_data->img->instances[0].x += move_timing;
			i++;
		}
		// game->character_data->img->instances[0].x += 128;
	}
	if (is_direction(game->mlx, MLX_KEY_W, MLX_KEY_UP))
	{
		ft_printf("Key pressed: %c\n", keydata.key);
		while (i < move_div)
		{
			game->character_data->img->instances[0].y -= move_timing;
			i++;
		}
		// game->character_data->img->instances[0].y -= 128;
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
	// int32_t			i;

	// i = 0;
	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game.mlx)
		ft_error();
	game.character_data = insert_img_data(&game, "./src/img/chopper_L.png");
	if (mlx_image_to_window(game.mlx, game.character_data->img,
			WIDTH_TILE * 0, HEIGHT_TILE * 0) < 0)
		ft_error();
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	// mlx_loop_hook(mlx, &ft_count_loop, &i);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.character_data->img);
	mlx_delete_texture(game.character_data->texture);
	free(game.character_data);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
