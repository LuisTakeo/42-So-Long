/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:03:36 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/23 21:10:03 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH_TILE 128
# define HEIGHT_TILE 128

# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/gnl/includes/get_next_line.h"
# include "../lib/libft/ft_printf/includes/ft_printf.h"

typedef struct s_image_data
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}	t_img_data;

typedef struct s_game
{
	mlx_t	*mlx;
	t_img_data	*wall_data;
	t_img_data	*floor_data;
	t_img_data	*character_data[2];
	t_img_data	*collectible_data;
}	t_game;

#endif
