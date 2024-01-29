/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:04 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/12/05 18:38:38 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_putnbrbase(unsigned int n, char *base_str, int is_upper, char *str)
{
	int				len;
	unsigned int	base_nbr;
	unsigned long	n_long;

	n_long = n;
	base_nbr = ft_strlen(base_str);
	len = 0;
	if (str && is_upper && n_long)
	{
		while (*str)
			len += ft_putchar_fd(ft_toupper(*str++), 1);
	}
	else if (str && n_long)
		len += ft_putstr_fd(str, 1);
	if (n_long >= base_nbr)
		len += ft_putnbrbase(n_long / base_nbr, base_str, is_upper, NULL);
	if (is_upper)
		len += ft_putchar_fd(ft_toupper(base_str[n_long % base_nbr]), 1);
	else
		len += ft_putchar_fd(base_str[n_long % base_nbr], 1);
	return (len);
}
