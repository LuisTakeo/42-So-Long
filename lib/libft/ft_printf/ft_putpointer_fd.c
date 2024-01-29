/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:24:32 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/12/05 15:45:34 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putpointer_fd(unsigned long int n, char *start, int c, int fd)
{
	int				len;
	unsigned long	base_nbr;

	if (n == 0)
		return (ft_putnull_fd("(nil)", fd));
	base_nbr = ft_strlen(HEX);
	len = 0;
	if (c)
		len += ft_putchar_fd(c, fd);
	if (start)
		len += ft_putstr_fd(start, fd);
	if (n >= base_nbr)
		len += ft_putpointer_fd(n / base_nbr, NULL, 0, fd);
	len += ft_putchar_fd(HEX[n % base_nbr], fd);
	return (len);
}
