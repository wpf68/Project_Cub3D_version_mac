/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:57:43 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/08 14:38:47 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
// #include <X11/keysym.h>  //

void    update(t_image *image, int key)
{

    t_game  *game;

    game = &image->game;
    
    if (key == TOUCH_RIGHT)     //  rotation droite
    {
        game->map.p.apos += game->map.p.rotspeed;
        if (game->map.p.apos >= 2 * M_PI)   //  pour garder un angle entre 0 et 2*PI
            game->map.p.apos = game->map.p.apos - (2 * M_PI);
    }
    else if (key == TOUCH_LEFT)     // rotation gauche
    {
        game->map.p.apos -= game->map.p.rotspeed;
        if (game->map.p.apos < 0)   //  pour garder un angle entre 0 et 2*PI
            game->map.p.apos = (2 * M_PI) + game->map.p.apos;
    }
    else if (key == TOUCH_W || key == TOUCH_UP)     // 13     avancer
        move_player(game, -1.0, 0);
    else if (key == TOUCH_S || key == TOUCH_DOWN)      // 1    reculer
        move_player(game, 1.0, 0);
    else if (key == TOUCH_A)      // 1    reculer
        move_player(game, 1.0, (M_PI / 2));
    else if (key == TOUCH_D)      // 1    reculer
        move_player(game, 1.0, -(M_PI / 2));
    else if (key == TOUCH_ESC)       //
        ft_close(image);

}

void    move_player(t_game *game, double nb, double alpha)
{
    double  tmp_x;
    double  tmp_y;
    double  apos;



    apos = game->map.p.apos + alpha;
    if (apos < 0)
        apos = (2 * M_PI) + apos;
    if (apos > 2 * M_PI)
        apos = apos - (2 * M_PI);


    game->map.p.pos.x = game->map.p.pos.x / game->rapport_player * 10;
    game->map.p.pos.y = game->map.p.pos.y / game->rapport_player * 10;

    tmp_x = game->map.p.pos.x + (game->map.p.speed * cos(apos)) * nb;
    if (game->map.tab[(int)floor(game->map.p.pos.y / 10)][(int)floor(tmp_x / 10)] == FLOOR &&
            game->map.tab[(int)floor(game->map.p.pos.y / 10) + 1][(int)floor(tmp_x / 10)] == FLOOR &&
            game->map.tab[(int)floor(game->map.p.pos.y / 10)][(int)floor(tmp_x / 10) + 1] == FLOOR &&
            game->map.tab[(int)floor(game->map.p.pos.y / 10) + 1][(int)floor(tmp_x / 10) + 1] == FLOOR)
        game->map.p.pos.x = tmp_x;
    else
        game->map.hit_wall = 1;
    tmp_y = game->map.p.pos.y + (game->map.p.speed * sin(apos)) * nb;
    if (game->map.tab[(int)floor(tmp_y / 10)][(int)floor(game->map.p.pos.x / 10)] == FLOOR && 
            game->map.tab[(int)floor(tmp_y / 10)][(int)floor(game->map.p.pos.x / 10) + 1] == FLOOR &&
            game->map.tab[(int)floor(tmp_y / 10) + 1][(int)floor(game->map.p.pos.x / 10)] == FLOOR &&
            game->map.tab[(int)floor(tmp_y / 10) + 1][(int)floor(game->map.p.pos.x / 10) + 1] == FLOOR)
        game->map.p.pos.y = tmp_y; 
    else
        game->map.hit_wall = 1; 

    game->map.p.pos.x = game->map.p.pos.x / 10 * game->rapport_player;
    game->map.p.pos.y = game->map.p.pos.y / 10 * game->rapport_player;

}