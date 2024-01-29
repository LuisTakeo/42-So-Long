/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:36:43 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/24 17:03:29 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	total_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = malloc(sizeof(char) * (total_len));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, s2, total_len);
	return (new_str);
}
