/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:22:49 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/04/02 14:23:44 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(args, int));
	else if (format == 'p')
		print_len += ft_ptr_print(va_arg(args, unsigned long long));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		print_len += ft_print_prc();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_print_formats(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
