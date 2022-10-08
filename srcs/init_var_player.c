/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:27:59 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/08 15:38:10 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_angle_player(t_game *game)
{
    int x;
    int y;

    x = -1;
    while (++x < game->map.lines)
    {
        y = -1;
        while (++y < game->map.columns)
        {
            if (game->map.tab[x][y] == SOUTH)
                game->map.p.apos = ((3 *M_PI) / 2);
            else if (game->map.tab[x][y] == EAST)
                game->map.p.apos = M_PI;
            else if (game->map.tab[x][y] == NORTH)
                game->map.p.apos = (M_PI / 2); 
            else if (game->map.tab[x][y] == WEST)
                game->map.p.apos = 0;
        }
    }
//	printf("apos = %f\n", game->map.p.apos); //

}


void    init_var_player(t_game *game)
{
    game->map.nb_player = 0;
    game->map.p.speed = 0.5;
    game->map.p.rotspeed = 0.1;
    game->map.hit_wall = 0;
    game->rapport_player = DEFINITION_TEXTURES;
    init_angle_player(game);
}