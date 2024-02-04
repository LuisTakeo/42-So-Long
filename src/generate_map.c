/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:17 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/02/04 05:05:35 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_list_to_arr(t_list *str_list)
{
	char	**arr_map;
	int32_t	arr_size;
	int32_t	i;
	t_list	*t_temp;

	arr_size = ft_lstsize(str_list);
	arr_map = malloc(sizeof(char *) * (arr_size + 1));
	i = -1;
	arr_map[arr_size] = NULL;
	while (++i < arr_size)
	{
		arr_map[i] = str_list->content;
		t_temp = str_list;
		str_list = str_list->next;
		free(t_temp);
	}
	return (arr_map);
}

t_list	*read_file_to_list(char *file)
{
	t_list	*str_list;
	char	*line;
	int32_t	fd;

	str_list = NULL;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		ft_lstadd_back(&str_list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (str_list);
}

char	**generate_map(char *file)
{
	char	**arr_map;
	t_list	*str_list;

	str_list = read_file_to_list(file);
	if (!str_list)
		return (NULL);
	arr_map = read_list_to_arr(str_list);
	return (arr_map);
}
