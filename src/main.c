/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/21 22:05:07 by tpaim-yu         ###   ########.fr       */
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

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_img_data	*img_data;

	img_data = (t_img_data *)param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_printf("Key pressed: %c\n", keydata.key);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		ft_printf("Key pressed: %c\n", keydata.key);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_printf("Key pressed: %c\n", keydata.key);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_printf("Key pressed: %c\n", keydata.key);
	if (img_data)
		return ;
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

int32_t	main(void)
{
	t_game	game;
	// mlx_t	*mlx;
	t_img_data	game_img;
	// int32_t			i;

	// i = 0;
	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game.mlx)
		ft_error();
	game_img.texture = mlx_load_png("./src/img/chopper_L.png");
	if (!(game_img.texture))
		ft_error();
	ft_printf("Width: %d\nHeight: %d\n", game_img.texture->width, game_img.texture->height);
	game_img.img = mlx_texture_to_image(game.mlx, game_img.texture);
	if (!game_img.img || (mlx_image_to_window(game.mlx, game_img.img, WIDTH_TILE * 0, HEIGHT_TILE * 0) < 0))
		ft_error();
	// if (!img || (mlx_image_to_window(mlx, img, 0, 128) < 0))
	// 	ft_error();
	// if (!img || (mlx_image_to_window(mlx, img, 5000, 0) < 0))
	// 	ft_error();
	// if (!img || (mlx_image_to_window(mlx, img, 128, 128) < 0))
	// 	ft_error();
	mlx_key_hook(game.mlx, &my_keyhook, &game_img);
	// mlx_loop_hook(mlx, &ft_count_loop, &i);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game_img.img);
	mlx_delete_texture(game_img.texture);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
