/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:44:45 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/30 20:49:49 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_valid_entry(char *entry, char *extension)
{
	int32_t	entry_len;
	int32_t	extens_len;

	entry_len = ft_strlen(entry) - 1;
	extens_len = ft_strlen(extension) - 1;
	while (extens_len >= 0)
		if (entry[entry_len--] != extension[extens_len--])
			exit(ft_printf("INVALIDO!"));
}

int	count_occ(char *str, char c)
{
	int	i;
	int	occ;

	occ = 0;
	if (!str)
		return (occ);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			occ++;
	return (occ);
}

void	verify_min_size(char **map)
{
	int32_t	l;

	l = -1;
	while (map[++l])
	{
		if (ft_strlen(map[l]) < 4)
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
	l = 0;
	while (map[++l])
	{
		c = 0;
		while (map[l][c] && map[l][c] != '\n')
			c++;
		if (c != t_map->last_col)
		{
			free_map(map);
			exit (ft_printf("Não é um retangulo"));
		}
	}
	t_map->last_line = l;
}

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
				exit (ft_printf("Não possui caracteres válidos"));
			}
		}
	}
	// if (map[l - 1][c] == '\n')
	// {
	// 	free_map(map);
	// 	exit (ft_printf("Quebra de linha no final"));
	// }

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

void	init_map_validator(t_valid_map *map)
{
	map->collectible_occ = 0;
	map->exit_occ = 0;
	map->ply_occ = 0;
	map->last_col = 0;
	map->last_line = 0;
}

void	flood_fill(char **map, int32_t l, int32_t c)
{
	if (map[l][c] != '1')
	{
		map[l][c] = '1';
		flood_fill(map, l + 1, c);
		flood_fill(map, l - 1, c);
		flood_fill(map, l, c + 1);
		flood_fill(map, l, c - 1);
	}
}

void	verify_map_flood(char **map)
{
	int32_t	l;
	int32_t	c;

	l = -1;
	while (map[++l])
	{
		c = -1;
		while (map[l][++c] != '\n')
		{
			if (ft_strchr("PCE", map[l][c]))
			{
				free_map(map);
				exit(ft_printf("Sem saída para o personagem"));
			}
		}

	}
}

void	verify_pathway(char **map)
{
	int32_t	l;
	int32_t	c;

	l = -1;
	c = 0;
	while (map[++l] && map[l][c] != 'P')
	{
		c = -1;
		while (map[l][++c])
			if (map[l][c] == 'P')
				flood_fill(map, l, c);
	}
	verify_map_flood(map);
}

void	validate_map(char *path)
{
	char		**map;
	t_valid_map	t_map;


	map = generate_map(path);
	if (!map)
		exit(ft_printf("Arquivo não existente"));
	init_map_validator(&t_map);
	verify_min_size(map);
	verify_rectangle(map, &t_map);
	verify_char_valid(map);
	verify_min_char(map, &t_map);
	verify_walls(map, &t_map);
	verify_pathway(map);
	free_map(map);
}
