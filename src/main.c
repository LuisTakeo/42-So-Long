/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/24 18:37:04 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "MLX42/MLX42.h"


// Exit the program as failure.
void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	delete_img_data(t_game *game, t_img_data *img_data)
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

// int32_t	count_lines(char *file)
// {
// 	int32_t	fd;
// 	int32_t	height;
// 	char	*line;

// 	fd = open(file, O_RDONLY);
// 	line = get_next_line(fd);

// 	close(fd);
// }

char	**read_file(char *file)
{
	char	**arr_map;
	char	*line;
	int32_t	fd;

	arr_map = NULL;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error();
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("Colunas: %d", ft_printf("%s", line));
		free(line);
		line = get_next_line(fd);
	}
	return (arr_map);
}

int32_t	main(void)
{
	t_game	game;
	// mlx_t	*mlx;
	int32_t	i;
	char	*file;
	char	**map;

	file = ft_strdup("./src/maps/map.ber");
	map = read_file(file);
	free(file);
	i = 0;
	// init game
	game.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game.mlx)
		ft_error();
	// init images
	game.character_data[0] = insert_img_data(&game, "./src/img/chopper_R.png");
	game.character_data[1] = insert_img_data(&game, "./src/img/chopper_L.png");
	game.wall_data = insert_img_data(&game, "./src/img/water.png");
	game.character_moves = 0;
	// insert images to window
	while (i < 10)
	{
		if (mlx_image_to_window(game.mlx, game.wall_data->img,
				WIDTH_TILE * i, HEIGHT_TILE * 0) < 0)
			ft_error();
		i++;
	}
	if ((mlx_image_to_window(game.mlx, game.character_data[0]->img,
				WIDTH_TILE * 2, HEIGHT_TILE * 0) < 0)
		|| mlx_image_to_window(game.mlx, game.character_data[1]->img,
			WIDTH_TILE * 2, HEIGHT_TILE * 0) < 0)
		ft_error();
	game.character_data[0]->img->enabled = 0;
	mlx_key_hook(game.mlx, &listen_moves, &game);
	// mlx_loop_hook(mlx, &ft_count_loop, &i);
	mlx_loop(game.mlx);
	delete_img_data(&game, game.character_data[0]);
	delete_img_data(&game, game.character_data[1]);
	delete_img_data(&game, game.wall_data);
	mlx_terminate(game.mlx);
	i = 0;
	// while (map[i])
	// 	free(map[i++]);
	// free(map);
	return (EXIT_SUCCESS);
}
