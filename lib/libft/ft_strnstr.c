/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:08:05 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/17 14:47:08 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	while (*s1 && (s2_len + i) <= len)
	{
		if (!ft_strncmp(s2, s1 + i, s2_len))
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
