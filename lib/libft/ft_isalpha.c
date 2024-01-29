/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:26 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/16 16:26:33 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islowcase(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

static int	ft_isupcase(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_islowcase(c) || ft_isupcase(c))
		return (1024);
	return (0);
}
