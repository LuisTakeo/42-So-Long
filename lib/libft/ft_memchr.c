/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:14:10 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/16 17:42:46 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (n == 0)
		return (NULL);
	str = (unsigned char *) s;
	i = 0;
	while (i < (n - 1) && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
		return ((void *)s + i);
	return (NULL);
}
