/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/29 21:46:10 by tpaim-yu         ###   ########.fr       */
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

void	count_colletibles(t_game *game)
{
	int32_t	c;
	int32_t	l;

	game->collectibles = 0;
	l = 0;
	while (game->map[l])
	{
		c = -1;
		ft_printf("linha: %s",game->map[l]);
		while (game->map[l][++c])
			if (game->map[l][c] == 'C')
				game->collectibles++;
		l++;
	}
	ft_printf("Coletáveis: %d", game->collectibles);
}

int32_t	main(void)
{
	t_game	game;
	char	*file;

	file = ft_strdup("./src/maps/map.ber");
	game.map = generate_map(file);
	free(file);
	count_colletibles(&game);
	game.player_moves = 0;
	init_game(&game);
	finish_game(&game);
	// mlx_loop_hook(mlx, &ft_count_loop, &i);
	// while (map[i])
	// 	free(map[i++]);
	// free(map);
	return (EXIT_SUCCESS);
}
