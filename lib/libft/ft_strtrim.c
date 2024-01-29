/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:27:14 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/20 15:36:57 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	dest = (char *)s1 + i;
	i = ft_strlen(dest) - 1;
	while (dest[i] && ft_strrchr(set, dest[i]))
		i--;
	return (ft_substr(dest, 0, i + 1));
}
