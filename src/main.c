/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/26 20:50:31 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
// mlx_put_string;

int32_t	main(void)
{
	t_game	game;
	int32_t	i;
	char	*file;

	file = ft_strdup("./src/maps/map.ber");
	game.map = generate_map(file);
	free(file);
	i = 0;
	// init game
	game.character_moves = 0;
	init_game(&game);
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
