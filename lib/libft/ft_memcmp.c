/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:19:16 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/16 17:56:40 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < (n - 1) && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
