/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:45:25 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/01 15:21:54 by pwolff           ###   ########.fr       */
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

	read_str = ft_strjoin("maps/", argv); //
	//ft_printf("chemin map : %s\n", read_str);  // ----------------  test
	map_fd = open(read_str, O_RDONLY); //
	free(read_str);   //

	
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
	game->map.columns = ft_strlen(game->map.tab[0]);
	free(temp);

}
