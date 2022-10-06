/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:46:30 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/06 09:56:56 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		move_test(int x, int y, t_image *images)
{
    double  rapport;
    double  apos_mouse;
    int     key;

  //  t_game  *game;
  //  game = &images->game;

    key = TOUCH_RIGHT;
    // rapport taille CUBE_X sur 90 degres ( PI / 2)

    if (x > CUBE_X || y > CUBE_Y)
        return (0);

    rapport = M_PI / 2.0 / CUBE_X;
    apos_mouse = rapport * x;

    apos_mouse = apos_mouse - (M_PI / 4);
    
  //  printf("Button = %d x = %d   --  Y = %d  key =  %d  apos = %f\n", button, x, y, key, apos_mouse);

   // printf("game.map.p.apos = %f\n", (images->game.map.p.apos));

    images->game.map.p.apos = images->game.map.p.apos + apos_mouse;


    if (images->game.map.p.apos < 0)   //  pour garder un angle entre 0 et 2*PI
            images->game.map.p.apos = (2 * M_PI) + images->game.map.p.apos;
    if (images->game.map.p.apos >= 2 * M_PI)   //  pour garder un angle entre 0 et 2*PI
            images->game.map.p.apos = images->game.map.p.apos - (2 * M_PI);

    
    if (apos_mouse < 0)
        key = TOUCH_LEFT;
    anim_direction(&images->legend, key);
    if (images->game.win_ptr == NULL)
        return (1);

    
   // ft_printf("key --> %d\n", key);

    anim_legend(&images->legend);  //  à la place du mlx_loop_hook du main
    anim_cub3D(images);
    reprint_pos(&images->game);    

    return (0);
}
