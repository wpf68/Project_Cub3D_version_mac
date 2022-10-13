/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:14:35 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/13 13:33:22 by pwolff           ###   ########.fr       */
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
            if (find_char(game->map.tab[i][j], " \t0123456789NSEW") == 0)
                return (0);
            printf("i = %d, j = %d\n", i, j);
        }
        j = -1;
    }
    printf("-------check_map_char_ok------\n");
    return (1);
}