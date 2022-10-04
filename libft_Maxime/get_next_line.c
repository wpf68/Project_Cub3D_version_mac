/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:02:56 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/04/04 14:31:17 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *temp)
{
	char	*tab;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		tab[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		tab[i] = temp[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_save(char *temp)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free (temp);
		return (NULL);
	}
	tab = (char *)malloc(sizeof(char) * (f_l(temp) - i + 1));
	if (!tab)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		tab[j++] = temp[i++];
	tab[j] = '\0';
	free (temp);
	return (tab);
}

char	*ft_read_and_save(int fd, char *temp)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(temp, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		temp = ft_s_join(temp, buff);
	}
	free (buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read_and_save(fd, temp);
	if (!temp)
		return (NULL);
	str = ft_get_line(temp);
	temp = ft_save(temp);
	return (str);
}
