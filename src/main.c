/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:02:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/30 15:37:40 by tpaim-yu         ###   ########.fr       */
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

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Quantia de parametros inválida.\n"));
	is_valid_entry(argv[1], ".ber");
	init_values(&game);
	validate_map(argv[1]);
	// file = ft_strdup("./src/maps/map.ber");
	game.map = generate_map(argv[1]);
	count_colletibles(&game);

	init_game(&game);
	finish_game(&game);
	// while (map[i])
	// 	free(map[i++]);
	// free(map);
	return (EXIT_SUCCESS);
}
