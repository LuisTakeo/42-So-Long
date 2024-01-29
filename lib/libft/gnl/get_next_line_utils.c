/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:38:53 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/01/24 16:27:20 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"
#include "../libft.h"

t_list_char	*ft_lstnew_char(char content)
{
	t_list_char	*new_list;

	new_list = malloc(sizeof(t_list_char));
	if (!new_list)
		return (NULL);
	new_list->c = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back_char(t_list_char **lst, t_list_char *new)
{
	t_list_char	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_lstclear_char(t_list_char **lst, void (*del)(void *))
{
	t_list_char	*temp;
	t_list_char	*first;

	first = *lst;
	if (!lst)
		return ;
	while (first)
	{
		temp = first->next;
		del(first);
		first = temp;
	}
	*lst = NULL;
}
