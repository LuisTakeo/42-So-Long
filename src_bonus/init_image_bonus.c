/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:15:06 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 19:15:06 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_exit_image(t_game *game)
{
	int32_t	l;
	int32_t	c;

	game->exit_data = insert_img_data(game, "./src_bonus/img/exit.png");
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
				if (img_to_win(game, game->exit_data, c, l))
					ft_error(game);
				return ;
			}
			c++;
		}
		l++;
	}
}

void	put_floor_image(t_game *game)
{
	int32_t	l;
	int32_t	c;
	int32_t	is_invalid;

	is_invalid = 0;
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (ft_strchr("0PCEX", game->map[l][c]))
				is_invalid += img_to_win(game, game->floor_data, c, l);
			if (is_invalid)
				ft_error(game);
			c++;
		}
		l++;
	}
}

void	init_map_image(t_game *game)
{
	int32_t	l;
	int32_t	c;
	int32_t	is_invalid;

	is_invalid = 0;
	game->wall_data = insert_img_data(game, "./src_bonus/img/water.png");
	game->floor_data = insert_img_data(game, "./src_bonus/img/floor.png");
	l = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == '1' || ft_strchr("0PCEX", game->map[l][c]))
				is_invalid += img_to_win(game, game->wall_data, c, l);
			if (is_invalid)
				ft_error(game);
			c++;
		}
		l++;
	}
	put_floor_image(game);
}

void	alloc_collectibles(t_game *game)
{
	int32_t	l;

	game->collect_data = malloc(
			sizeof (t_img_data *) * (game->collectibles + 1));
	game->collect_data[game->collectibles] = NULL;
	l = -1;
	while (++l < game->collectibles)
		game->collect_data[l] = insert_img_data(
				game, "./src_bonus/img/collect.png");
}

void	init_collectible_image(t_game *game)
{
	int32_t	l;
	int32_t	c;
	int32_t	x;
	int32_t	is_invalid;

	is_invalid = 0;
	l = 0;
	x = 0;
	alloc_collectibles(game);
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
		{
			if (game->map[l][c] == 'C')
			{
				is_invalid += img_to_win(
						game, game->collect_data[x++], c, l);
			}
			if (is_invalid)
				ft_error(game);
			c++;
		}
		l++;
	}
}
