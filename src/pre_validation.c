/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:44:45 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/30 16:35:30 by tpaim-yu         ###   ########.fr       */
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
		while (map[l][c] != '\n')
			c++;
		if (c != t_map->last_col)
		{
			free_map(map);
			exit (ft_printf("Não é um retangulo"));
		}

	}
}

void	validate_map(char *path)
{
	char		**map;
	t_valid_map	t_map;

	map = generate_map(path);
	if (!map)
		exit(ft_printf("Arquivo não existente"));
	verify_min_size(map);
	verify_rectangle(map, &t_map);
	free_map(map);
}
