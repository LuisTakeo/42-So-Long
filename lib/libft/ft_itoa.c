/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:30:03 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/10/20 02:13:37 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_numtostr(int n, char *str, int len)
{
	int	i;

	i = len - 1;
	if (n == -2147483648)
	{
		str[0] = '-';
		str[i] = (n % 10) * -1 + '0';
		n /= 10 * -1;
		i--;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[i] = (n % 10) + '0';
	str[len] = '\0';
	return (str);
}

static int	ft_count_digits(int n)
{
	int	occ;

	occ = 0;
	if (n == -2147483648)
	{
		n = (n / 10) * -1;
		occ += 2;
	}
	if (n < 0)
	{
		n = n * -1;
		occ++;
	}
	while (n >= 10)
	{
		n /= 10;
		occ++;
	}
	occ++;
	return (occ);
}

char	*ft_itoa(int n)
{
	int		nbr_len;
	char	*nbr_str;

	nbr_len = ft_count_digits(n);
	nbr_str = malloc((sizeof(char) * nbr_len) + 1);
	if (!nbr_str)
		return (NULL);
	ft_numtostr(n, nbr_str, nbr_len);
	return (nbr_str);
}
