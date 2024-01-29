/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:10:37 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/30 17:52:55 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*new_temp;

	if (!lst)
		return (NULL);
	temp = lst;
	new_lst = NULL;
	while (temp)
	{
		new_temp = ft_lstnew(f(temp->content));
		if (!new_temp)
		{
			ft_lstclear(&new_lst, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_temp);
		temp = temp->next;
	}
	return (new_lst);
}
