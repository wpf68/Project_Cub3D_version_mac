/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:26 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/18 09:11:23 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_data_and_map2(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.lines)
	{
		if (game->map.columns < (int)ft_strlen(game->map.tab[i]))
				game->map.columns = ft_strlen(game->map.tab[i]);
	}
}

static int	parse_data_and_map3(t_game *game)
{
	int		map_fd;

	map_fd = open(game->read_str, O_RDONLY);
	free(game->read_str);
	if (map_fd == -1)
		error_msg("Error:\nLa map n' a pas pu s'ouvir !");
	game->read_str = get_next_line(map_fd);
	return (map_fd);
}

static void	empty_map(t_game *game)
{
	if (game->map.tab[0] == NULL)
		error_msg("Error:\nLa map n'a pas pu s'ouvrir !");
}

void	parse_data_and_map(t_game *game, t_game *cube)
{
	int		map_fd;
	char	*temp;
	char	*temp2;

	map_fd = parse_data_and_map3(game);
	temp = ft_strdup("");
	while (game->read_str)
	{
		if (game->parse.read_map == 0)
			parse_text_and_color(game->read_str, cube, game);
		if (game->parse.read_map == 1)
		{
			if (empty_line(game->read_str))
				error_msg("Error:\nla map contient une ligne vide !");
			temp2 = temp;
			temp = ft_strjoin(temp2, game->read_str);
			free (temp2);
			game->map.lines += 1;
		}
		game->read_str = get_next_line(map_fd);
	}
	close (map_fd);
	game->map.tab = ft_split(temp, '\n');
	empty_map(game);
}
