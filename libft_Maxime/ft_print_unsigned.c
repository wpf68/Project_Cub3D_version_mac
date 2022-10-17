/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:17:31 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/04/02 14:17:51 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_num(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*tab;
	int		len;

	len = ft_len_num(nb);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	tab[len] = '\0';
	while (nb != 0)
	{
		tab[len - 1] = nb % 10 + 48;
		nb = nb / 10 ;
		len--;
	}
	return (tab);
}

int	ft_print_unsigned(unsigned int nb)
{
	int		print_len;
	char	*tab;

	print_len = 0;
	if (nb == 0)
		print_len += write(1, "0", 1);
	else
	{
		tab = ft_uitoa(nb);
		print_len += ft_print_str(tab);
		free(tab);
	}
	return (print_len);
}
