/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:22:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/17 09:53:53 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_first_line(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.tab[0][i])
	{
		if ((game->map.tab[0][i] >= '1' && game->map.tab[0][i] <= '9')
			|| game->map.tab[0][i] == ' ')
			i++;
		else if (find_char(game->map.tab[0][i], "0NSEW"))
			return (0);
	}
	return (1);
}

int	check_last_line(t_game *game)
{
	int	i;
	int	end;

	i = 0;
	end = index_last_line(game) - 1;
	while (game->map.tab[end][i])
	{
		if ((game->map.tab[end][i] >= '1' && game->map.tab[end][i] <= '9')
			|| game->map.tab[end][i] == ' ')
			i++;
		else if (find_char(game->map.tab[i][end], "0NSEW"))
			return (0);
	}
	return (1);
}

int	check_first_column(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.tab[i])
	{
		if ((game->map.tab[i][0] >= '1' && game->map.tab[i][0] <= '9') \
			|| game->map.tab[i][0] == ' ')
			i++;
		else if (find_char(game->map.tab[i][0], "0NSEW"))
			return (0);
	}
	return (1);
}

int	check_last_column(t_game *game)
{
	int	i;
	int	end;

	i = 0;
	while (game->map.tab[i])
	{
		end = ft_strlen(game->map.tab[i]) - 1;
		if ((game->map.tab[i][end] >= '1' && game->map.tab[i][end] <= '9')
			|| game->map.tab[i][end] == ' ')
			i++;
		else if (find_char(game->map.tab[i][end], "0NSEW"))
			return (0);
	}
	return (1);
}

int	check_border_map(t_game *game)
{
	if (check_first_line(game) == 0)
		return (0);
	if (check_last_line(game) == 0)
		return (0);
	if (check_first_column(game) == 0)
		return (0);
	if (check_last_column(game) == 0)
		return (0);
	return (1);
}
