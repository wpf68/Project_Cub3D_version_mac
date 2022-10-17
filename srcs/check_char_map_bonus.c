/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:14:35 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/11 10:16:33 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_char_map_bonus(t_game *game)
{
     int i;
    int j;

    i = -1;
    j = -1;
    while (++i < game->map.lines)
    {
        while (++j < game->map.columns)
        {
            if (find_char(game->map.tab[i][j], " 0123456789NSEW") == 0)
                return (0);
        }
        j = -1;
    }
    return (1);
}