/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:46:53 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/16 17:33:42 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	size_value;

	size_value = ft_strlen(s) + 1;
	new_str = (char *)malloc(size_value);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, size_value);
	return (new_str);
}
