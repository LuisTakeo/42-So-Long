/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:32:43 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/18 17:15:51 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

static ssize_t	count_line_len(t_list_char *t_char, char n)
{
	ssize_t		len;
	t_list_char	*t_temp;

	len = 0;
	t_temp = t_char;
	if (!n)
	{
		if (t_temp && !t_temp->next)
			return (1);
		while (t_temp)
		{
			len++;
			t_temp = t_temp->next;
		}
		return (++len);
	}
	while (t_temp && t_temp->c != n)
	{
		len++;
		t_temp = t_temp->next;
	}
	if (t_temp && t_temp->c == n)
		len++;
	return (len);
}

static char	*create_new_line(t_list_char **t_char_node)
{
	ssize_t		i;
	t_list_char	*t_new_node;
	char		*new_line;
	ssize_t		len;

	t_new_node = *t_char_node;
	i = 0;
	len = count_line_len(*t_char_node, '\n');
	new_line = ft_calloc(sizeof(char), len + 1);
	while (t_new_node && t_new_node->c != '\n')
	{
		new_line[i++] = t_new_node->c;
		t_new_node = t_new_node->next;
		free(*t_char_node);
		*t_char_node = t_new_node;
	}
	if (!t_new_node)
	{
		new_line[i] = '\0';
		return (new_line);
	}
	new_line[i] = t_new_node->c;
	*t_char_node = t_new_node->next;
	free(t_new_node);
	return (new_line);
}

static void	create_new_node(int fd, char *buf, ssize_t rd, t_list_char	**t_ch)
{
	ssize_t	occ_break_line;
	ssize_t	i;

	occ_break_line = 0;
	while (rd > 0)
	{
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
				occ_break_line = 1;
			ft_lstadd_back_char(&*t_ch, ft_lstnew_char(buf[i++]));
		}
		if (occ_break_line)
			break ;
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			ft_lstclear_char(t_ch, free);
			free(buf);
			return ;
		}
		buf[rd] = '\0';
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	char				*buffer;
	char				*new_line;
	t_list_char static	*t_char_node[1024];
	ssize_t				r;

	if (fd < 0 || fd > 1024)
		return (NULL);
	r = 0;
	buffer = ft_calloc(sizeof (char), (BUFFER_SIZE + 1));
	r = read(fd, buffer, BUFFER_SIZE);
	if (r == -1)
	{
		ft_lstclear_char(&t_char_node[fd], free);
		free (buffer);
		return (NULL);
	}
	if ((!buffer || r <= 0 || fd < 0 || BUFFER_SIZE <= 0) && !t_char_node[fd])
	{
		free (buffer);
		return (NULL);
	}
	buffer[r] = '\0';
	create_new_node(fd, buffer, r, &t_char_node[fd]);
	new_line = create_new_line(&t_char_node[fd]);
	return (new_line);
}
