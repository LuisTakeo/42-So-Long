/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:59 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/30 18:49:51 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*ft_free_arr(char **arr_str, int i)
{
	while (i > 0)
		free(arr_str[--i]);
	free(arr_str);
	return (NULL);
}

static char	**ft_alloc_words(char const *s, char **arr_str, char c, int arr_s)
{
	int		i;
	int		j;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	while (a < arr_s)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		str = (char *)s + i;
		while (s[i] && s[i++] != c)
			j++;
		arr_str[a] = ft_substr(str, 0, j);
		if (!arr_str[a])
			return (ft_free_arr(arr_str, a));
		a++;
	}
	arr_str[a] = NULL;
	return (arr_str);
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**arr_str;

	count_words = ft_count_words(s, c);
	arr_str = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!count_words || !s)
	{
		arr_str[0] = NULL;
		return (arr_str);
	}
	if (!arr_str)
	{
		free(arr_str);
		return (arr_str);
	}
	return (ft_alloc_words(s, arr_str, c, count_words));
}
