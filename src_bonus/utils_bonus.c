/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:10:15 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/31 19:10:15 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	is_valid_entry(char *entry, char *extension)
{
	int32_t	entry_len;
	int32_t	extens_len;

	entry_len = ft_strlen(entry) - 1;
	extens_len = ft_strlen(extension) - 1;
	while (extens_len >= 0)
		if (entry[entry_len--] != extension[extens_len--])
			exit(ft_printf("Formato inválido."));
}

int	count_occ(char *str, char c)
{
	int	i;
	int	occ;

	occ = 0;
	if (!str)
		return (occ);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			occ++;
	return (occ);
}
