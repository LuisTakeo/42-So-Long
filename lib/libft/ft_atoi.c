/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:33:40 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/16 14:24:44 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issignal(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	is_negative;

	is_negative = 0;
	result = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issignal(nptr[i]))
	{
		if (nptr[i] == '-')
			is_negative = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (is_negative)
		result *= -1;
	return (result);
}
