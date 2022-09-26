/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:54:51 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/08/16 10:56:33 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_raycasting(t_game *game)
{
    game->r.hit = 0;
    game->r.map_x = floor(game->map.p.pos.x);
    game->r.map_y = floor(game->map.p.pos.y);
    game->r.p = 0;
    game->r.ratio = (game->r.p - (WIDTH / 2)) / (WIDTH / 2);
    game->r.dir_x = cos(game->map.p.apos) / 2 + cos(game->map.p.apos - 0.25) \
    * game->r.ratio;
    game->r.dir_y = sin(game->map.p.apos) / 2 + sin(game->map.p.apos - 0.25) \
    * game->r.ratio;
    game->r.delta_x = sqrt(1 + (((int)game->r.dir_y ^ 2) / ((int)game->r.dir_x ^ 2)));
    game->r.delta_y = sqrt(1 + (((int)game->r.dir_x ^ 2) / ((int)game->r.dir_y ^ 2)));
}

void check_dist(t_game *game)
{
    if (game->r.dir_x < 0)
    {
        game->r.stepx = -1;
        game->r.sdist_x = (game->map.p.pos.x - game->r.map_x) * game->r.delta_x;
    }
    else
    {
        game->r.stepx = 1;
        game->r.sdist_x = ((game->r.map_x + 1) - game->map.p.pos.x) * game->r.delta_x;
    }
    if (game->r.dir_y < 0)
    {
        game->r.stepy = -1;
        game->r.sdist_y = (game->map.p.pos.y - game->r.map_y) * game->r.delta_y;
    }
    else
    {
        game->r.stepy = 1;
        game->r.sdist_y = ((game->r.map_y + 1) - game->map.p.pos.y) * game->r.delta_y;
    }
}

void check_walls(t_game *game)
{
    if (game->r.sdist_y < 0 || game->r.sdist_x > 0 && (game->r.sdist_x < game->r.sdist_y))
    {
        game->r.sdist_x += game->r.delta_x;
        game->r.map_x += game->r.stepx;
        game->r.side = 0;
    }
    else
    {
        game->r.sdist_y += game->r.delta_y;
        game->r.map_y += game->r.stepy;
        game->r.side = 1;
    }
    if (game->map.tab[(int)game->r.map_y][(int)game->r.map_x] != 0)
    {
        game->r.hit = 1;
    }
}

void correct_walls(t_game *game)
{
    if (game->r.side == 0)
    game->r.p_walldist = (game->r.map_x - game->map.p.pos.x \
    + (1 - game->r.stepx) / game->r.dir_x);
    else
    game->r.p_walldist = (game->r.map_y - game->map.p.pos.y \
    + (1 - game->r.stepy) / game->r.dir_y);
}