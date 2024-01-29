/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:15:54 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/10 19:40:13 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int c, int fd)
{
	int	len;

	len = 0;
	if (c && n >= 0)
		len += ft_putchar_fd(c, 1);
	if (n == -2147483648)
	{
		len += ft_putchar_fd('-', fd);
		len += ft_putnbr_fd((n / 10) * -1, 0, fd);
		len += ft_putchar_fd(((n % 10) * -1) + '0', fd);
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
		len += ft_putnbr_fd(n / 10, 0, fd);
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
