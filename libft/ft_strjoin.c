/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:42:44 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/04/05 08:00:51 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lengthcat(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	int				length;

	i = 0;
	j = 0;
	length = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	length = (i + j);
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	int				size;
	char			*tab;

	if (!s1 || !s2)
		return (NULL);
	size = lengthcat(s1, s2);
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!(tab))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}
