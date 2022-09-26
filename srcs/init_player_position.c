/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:58:16 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/08/01 12:52:08 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_player_position(t_game *game, char *line, int y)
{
    int x;

    x = 0;
    while ((line[x] != '\0') && find_player(line[x], "NSEW") == 0)
    x++;
    if (line[x] == '\0')
    return ;
    game->map.p.pos.x = x * 10;
    game->map.p.pos.y = y * 10;
}