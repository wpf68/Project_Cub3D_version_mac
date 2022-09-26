/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:11:46 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/03/02 10:04:38 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const	*s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	if (s == NULL)
		return (NULL);
	if (start > i)
		len = 0;
	if (i + start < len)
		len = i + start;
	tab = malloc(sizeof(char) * (len + 1));
	if (!(tab))
		return (NULL);
	while (s[start] != '\0' && j < len)
		tab[j++] = s[start++];
	tab[j] = '\0';
	return (tab);
}
