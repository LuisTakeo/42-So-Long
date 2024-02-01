/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_valid_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:08:31 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 19:08:31 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	verify_char_valid(char **map)
{
	int32_t	l;
	int32_t	c;

	l = -1;
	while (map[++l])
	{
		c = -1;
		while (map[l][++c] && map[l][c] != '\n')
		{
			if (!ft_strchr("1E0CP", map[l][c]))
			{
				free_map(map);
				exit (ft_printf("Não possui todos caracteres válidos."));
			}
		}
	}
	if (map[l - 1][c] == '\n')
	{
		free_map(map);
		exit (ft_printf("Quebra de linha no final"));
	}

}

void	verify_min_char(char **map, t_valid_map *t_map)
{
	int32_t	l;

	l = -1;
	while (map[++l])
	{
		t_map->ply_occ += count_occ(map[l], 'P');
		t_map->collectible_occ += count_occ(map[l], 'C');
		t_map->exit_occ += count_occ(map[l], 'E');
	}
	if (t_map->ply_occ != 1 || t_map->exit_occ != 1
		|| t_map->collectible_occ == 0)
	{
		free_map(map);
		exit (ft_printf("Quantia inválida de Player, Exit e/ou Coletáveis"));
	}
}

void	verify_walls(char **map, t_valid_map *t_map)
{
	int32_t	lst_line;
	int32_t	lst_column;
	int32_t	i;
	int32_t	occ_invalid;

	lst_column = t_map->last_col - 1;
	lst_line = t_map->last_line - 1;
	occ_invalid = 0;
	if ((count_occ(map[0], '1') != t_map->last_col)
		|| (count_occ(map[lst_line], '1') != t_map->last_col))
		occ_invalid = 1;
	i = -1;
	while (map[++i])
		if (map[i][0] != '1' || map[i][lst_column] != '1')
			occ_invalid = 1;
	if (occ_invalid)
	{
		free_map(map);
		exit(ft_printf("Paredes inválidas"));
	}
}
