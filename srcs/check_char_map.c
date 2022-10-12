/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:05:24 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/12 13:50:01 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_map_char(t_game *game)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (game->map.tab[++i])
    {
        while (game->map.tab[i][++j])
        {
            if (find_char(game->map.tab[i][j], " \t01NSEW") == 0)
                return (0);
            printf("i = %d, j = %d\n", i, j);
        }
        j = -1;
    }
    printf("-------check_map_char_ok------\n");
    return (1);
}