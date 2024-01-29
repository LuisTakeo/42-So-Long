/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:33:30 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/18 17:16:35 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>


typedef struct s_list_c
{
	char			c;
	struct s_list_c	*next;
}	t_list_char;

char		*get_next_line(int fd);
void		*ft_calloc(size_t nmemb, size_t size);
t_list_char	*ft_lstnew_char(char c);
void		ft_lstadd_back_char(t_list_char **lst, t_list_char *new);
void		ft_lstclear_char(t_list_char **lst, void (*del)(void *));

#endif
