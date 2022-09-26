/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:57:43 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/26 11:16:50 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
// #include <X11/keysym.h>  //

void    update(t_game *game, int key)
{

    
    
    if (key == 124 || key == 124)     //  123  rotation droite
        game->map.p.apos += game->map.p.rotspeed;
    if (key == 123 || key == 123)     // 124   rotation gauche
        game->map.p.apos -= game->map.p.rotspeed;
    if (key == 125 || key == 1)     // 13     avancer
        move_player(game, 1.0);
    if (key == 126 || key == 13)      // 1    reculer
        move_player(game, -1.0);
    if (key == 53)       //
    {
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);       // segment fautl !!!
        game->win_ptr = NULL;  // ok plus de segment fault mais le prg ne sort pas
        mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
       // mlx_destroy_image(legend.mlx_ptr, legend.img.mlx_img);

	  //  mlx_destroy_display(game->mlx_ptr);
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	    free(game->mlx_ptr);
        exit (0);
    }

}

void    move_player(t_game *game, double nb)
{
    double  tmp_x;
    double tmp_y;

     tmp_x = game->map.p.pos.x + (game->map.p.speed * cos(game->map.p.apos)) * nb;
     if (game->map.tab[(int)floor(game->map.p.pos.y / 10)][(int)floor(tmp_x / 10)] == FLOOR)
         game->map.p.pos.x = tmp_x;
     tmp_y = game->map.p.pos.y + (game->map.p.speed * sin(game->map.p.apos)) * nb;
     if (game->map.tab[(int)floor(tmp_y / 10)][(int)floor(game->map.p.pos.x / 10)] == FLOOR)
         game->map.p.pos.y = tmp_y;        
}