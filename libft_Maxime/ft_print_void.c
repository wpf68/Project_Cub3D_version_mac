/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:15:38 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/04/02 14:16:17 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

void	ft_ptr_put(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_ptr_put(nb / 16);
		ft_ptr_put(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_ptr_print(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	print_len += write (1, "0x", 2);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_ptr_put(ptr);
		print_len += ft_ptr_len(ptr);
	}
	return (print_len);
}
