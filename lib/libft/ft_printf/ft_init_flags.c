/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:17:14 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/12/07 16:00:40 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.is_space = 0;
	flags.is_hash = 0;
	flags.is_plus = 0;
	flags.is_width = 0;
	return (flags);
}
