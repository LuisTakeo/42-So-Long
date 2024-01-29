/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:17:39 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/30 16:52:41 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*first;

	first = *lst;
	if (!lst)
		return ;
	while (first)
	{
		temp = first->next;
		ft_lstdelone(first, del);
		first = temp;
	}
	*lst = NULL;
}
