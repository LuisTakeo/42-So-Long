/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:17:38 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/27 05:40:25 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == i)
		return (i);
	if (n < i)
	{
		while (s1[i] == s2[i])
			i++;
	}
	else
	{
		while ((i < (n - 1)) && (s1[i] == s2[i]) && s1[i])
			i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
