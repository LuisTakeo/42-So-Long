/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:05 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 17:36:05 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	flood_fill(char **map, int32_t l, int32_t c)
{
	if (!ft_strchr("1X", map[l][c]))
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
		c = 0;
		while (map[l][c] && map[l][c] != '\n')
		{
			if (ft_strchr("PCE", map[l][c]))
			{
				free_map(map);
				exit(ft_printf("Sem saída para o personagem"));
			}
			c++;
		}
	}
}

void	verify_pathway(char **map)
{
	int32_t	l;
	int32_t	c;

	l = 0;
	c = 0;
	while (map[l])
	{
		c = -1;
		while (map[l][++c])
			if (map[l][c] == 'P')
				flood_fill(map, l, c);
		l++;
	}
	verify_map_flood(map);
}
