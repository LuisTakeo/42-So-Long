/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:23:21 by tpaim-yu          #+#    #+#             */
/*   Updated: 2023/12/07 17:26:44 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	ft_filter_to_print_args(int c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, const char *), 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 0, 1));
	if (c == 'u')
		return (ft_putunsnbr_fd(va_arg(args, unsigned int), 1));
	if (c == 'x')
		return (ft_putnbrbase(va_arg(args, unsigned int), HEX, 0, 0));
	if (c == 'X')
		return (ft_putnbrbase(va_arg(args, unsigned int), HEX, 1, 0));
	if (c == 'p')
		return (ft_putpointer_fd((unsigned long int) va_arg(args, void *),
				"0x", 0, 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static int	ft_print_flags(char c, va_list args, t_flags flags)
{
	if (c == 'd' || c == 'i' || c == 'p')
	{
		if (flags.is_plus && (c == 'd' || c == 'i'))
			return (ft_putnbr_fd(va_arg(args, int), '+', 1));
		if (flags.is_plus && (c == 'p'))
			return (ft_putpointer_fd((unsigned long int) va_arg(args, void *),
					"0x", '+', 1));
		if (flags.is_space && (c == 'd' || c == 'i'))
			return (ft_putnbr_fd(va_arg(args, int), ' ', 1));
		if (flags.is_space && (c == 'p'))
			return (ft_putpointer_fd((unsigned long int) va_arg(args, void *),
					"0x", ' ', 1));
		if (c == 'd' || c == 'i')
			return (ft_putnbr_fd(va_arg(args, int), 0, 1));
		if (c == 'p')
			return (ft_putpointer_fd((unsigned long int) va_arg(args, void *),
					"0x", 0, 1));
	}
	if (c == 'X' && (flags.is_hash))
		return (ft_putnbrbase(va_arg(args, unsigned int), HEX, 1, "0X"));
	if (c == 'x' && (flags.is_hash))
		return (ft_putnbrbase(va_arg(args, unsigned int), HEX, 0, "0x"));
	if (c == 's' && (flags.is_width))
		return (ft_putstrspc_fd(va_arg(args, const char *), flags.is_width, 1));
	return (ft_filter_to_print_args(c, args));
}

static void	ft_verify_flags(char flag, t_flags *flags)
{
	if (flag == '+')
		flags->is_plus = 1;
	if (flag == ' ')
		flags->is_space = 1;
	if (flag == '#')
		flags->is_hash = 1;
	if (ft_isdigit(flag))
		flags->is_width = 1;
}

static int	ft_filter_to_print(const char *str, va_list args, unsigned int *i)
{
	t_flags			flags;

	flags = ft_init_flags();
	while (!ft_strchr("cspdiuxX%", str[*i]))
	{
		ft_verify_flags(str[*i], &flags);
		*i = *i + 1;
	}
	return (ft_print_flags(str[*i], args, flags));
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	len;

	if (!str)
		return (-1);
	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("# +", str[i]))
				len += ft_filter_to_print(str, args, &i);
			else
				len += ft_filter_to_print_args(str[i], args);
		}
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
