/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrspc_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:50 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/12/07 17:04:35 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putstrspc_fd(const char *str, int width, int fd)
{
	int	len;

	len = 0;
	if (width && str)
		len += ft_putchar_fd(' ', fd);
	len += ft_putstr_fd(str, fd);
	return (len);
}
