/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:58:16 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/16 10:01:43 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_position(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while ((line[x] != '\0') && find_player(line[x], "NSEW") == 0)
	x++;
	if (line[x] == '\0')
		return ;
	game->map.p.pos.x = x * game->rapport_player;
	game->map.p.pos.y = y * game->rapport_player;
}
