/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/21 18:31:23 by tpaim-yu         ###   ########.fr       */
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

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_printf("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_printf("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		ft_printf("!");
	if (param)
		return ;
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_error();
	texture = mlx_load_png("./src/img/chopper_L.png");
	if (!texture)
		ft_error();
	ft_printf("Width: %d\nHeight: %d\n", texture->width, texture->height);
	img = mlx_texture_to_image(mlx, texture);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	if (!img || (mlx_image_to_window(mlx, img, 0, 128) < 0))
		ft_error();
	if (!img || (mlx_image_to_window(mlx, img, 128, 0) < 0))
		ft_error();
	if (!img || (mlx_image_to_window(mlx, img, 128, 128) < 0))
		ft_error();
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
