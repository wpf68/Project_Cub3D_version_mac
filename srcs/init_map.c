/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:45:25 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/12 09:48:19 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map(t_game *game, char *argv)
{
	char	*read_str;
	char	*temp_temp;
	char	*temp;
	int		map_fd;
	int		i;

	i = 0;

	game->map.columns = 0;
	read_str = ft_strjoin("maps/", argv);
	map_fd = open(read_str, O_RDONLY); 
	free(read_str);
	if (map_fd == -1)
		error_msg("La map n'a pas pu s'ouvrir !");
	read_str = get_next_line(map_fd);
	temp = ft_strdup("");
	while (read_str)
	{
		temp_temp = temp;
		temp = ft_strjoin(temp_temp, read_str);
		free(temp_temp);
		read_str = get_next_line(map_fd);
		i++;
	}
	close (map_fd);
	game->map.tab = ft_split(temp, '\n');
	game->map.lines = i;
	i = 0;
	while (i < game->map.lines)
	{
		if (game->map.columns < (int)ft_strlen(game->map.tab[i]))
				game->map.columns = ft_strlen(game->map.tab[i]);
		printf(" i = %d\n", i);
		i++;
	}
		write(1, "******\n", 7);

	i = 0;
	while (game->map.tab[i])
	{
		printf(" i = %d   lines = %d\n", i, game->map.lines);
		printf("%s", game->map.tab[i]);
		i++;

	}
		write(1, "******\n", 7);

	
	free(temp);
}
