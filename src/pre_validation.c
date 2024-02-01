/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:44:45 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 19:11:18 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_min_size(char **map)
{
	int32_t	l;

	l = -1;
	while (map[++l])
	{
		if (ft_strlen(map[l]) < 3)
		{
			free_map(map);
			exit(ft_printf("Tamanho inválido"));
		}
	}
	if (l < 3)
	{
		free_map(map);
		exit(ft_printf("Tamanho inválido"));
	}

}

void	verify_rectangle(char **map, t_valid_map *t_map)
{
	int32_t	l;
	int32_t	c;

	c = 0;
	while (map[0][c] != '\n')
		c++;
	t_map->last_col = c;
	ft_printf("Tamanho retangulo: %d\n", c);
	l = 0;
	while (map[++l])
	{
		c = 0;
		while (map[l][c] && map[l][c] != '\n')
			c++;
		ft_printf("Tamanho linha atual: %d\n", c);
		if (c != t_map->last_col)
		{
			free_map(map);
			ft_printf("Linha: %d Coluna: %d", l, c);
			exit (ft_printf("Não é um retangulo"));
		}
	}
	t_map->last_line = l;
}

void	init_map_validator(t_valid_map *map)
{
	map->collectible_occ = 0;
	map->exit_occ = 0;
	map->ply_occ = 0;
	map->last_col = 0;
	map->last_line = 0;
}

void	validate_map(char *path)
{
	char		**map;
	t_valid_map	t_map;


	map = generate_map(path);
	if (!map)
		exit(ft_printf("Arquivo inválido ou não existente"));
	init_map_validator(&t_map);
	verify_min_size(map);
	verify_char_valid(map);
	verify_rectangle(map, &t_map);
	verify_min_char(map, &t_map);
	verify_walls(map, &t_map);
	verify_pathway(map);
	free_map(map);
}
