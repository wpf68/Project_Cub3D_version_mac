/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:31:46 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/03/01 09:46:48 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((b1[i] != '\0' || b2[i] != '\0') && i < n)
	{
		if (b1[i] > b2[i])
			return (1);
		else if (b1[i] < b2[i])
			return (-1);
		else if (b1[i] == b2[i] && b2[i] != '\0')
			i++;
	}
	return (0);
}
