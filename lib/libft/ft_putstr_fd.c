/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:46:19 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/10 19:51:20 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	i;
	int	len;

	len = 0;
	if (!str)
		return (ft_putnull_fd("(null)", fd));
	i = -1;
	while (str[++i])
		len += ft_putchar_fd(str[i], fd);
	return (len);
}

