/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:23:15 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/12/05 14:07:00 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putunsnbr_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsnbr_fd(n / 10, fd);
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
