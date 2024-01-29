/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:23:54 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/10 19:37:30 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX "0123456789abcdef"

# include "../../libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	is_space;
	int	is_hash;
	int	is_plus;
	int	is_width;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_putnbrbase(unsigned int n, char *base_str, int is_upper, char *str);
int		ft_putunsnbr_fd(unsigned int n, int fd);
int		ft_putpointer_fd(unsigned long int n, char *start, int c, int fd);
t_flags	ft_init_flags(void);
int		ft_putstrspc_fd(const char *str, int width, int fd);

#endif
