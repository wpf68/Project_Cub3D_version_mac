/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:55:45 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/04/02 13:57:47 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	f_l(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_s_join(char *temp, char *buff)
{
	size_t	i;
	size_t	j;
	char	*tab;

	if (!temp)
	{
		temp = (char *)(malloc(sizeof(char) * 1));
		temp[0] = '\0';
	}
	if (!temp || !buff)
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (f_l(temp) + f_l(buff)+ 1));
	if (!tab)
		return (NULL);
	i = -1;
	j = 0;
	while (temp[++i] != '\0')
		tab[i] = temp[i];
	while (buff[j])
		tab[i++] = buff[j++];
	tab[i] = '\0';
	free (temp);
	return (tab);
}
