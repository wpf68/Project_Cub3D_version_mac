/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:46:32 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 15:59:05 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		movements_mouse(int button, int x, int y, t_image *images)
{
    (void)  button;
    double  rapport;
    double  apos_mouse;
    int     key;

    key = TOUCH_RIGHT;

    if (x > CUBE_X || y > CUBE_Y)
        return (0);

    rapport = M_PI / 2.0 / CUBE_X;
    apos_mouse = rapport * x;
    apos_mouse = apos_mouse - (M_PI / 4);
    images->game.map.p.apos = images->game.map.p.apos + apos_mouse;
    if (images->game.map.p.apos < 0)
            images->game.map.p.apos = (2 * M_PI) + images->game.map.p.apos;
    if (images->game.map.p.apos >= 2 * M_PI)
            images->game.map.p.apos = images->game.map.p.apos - (2 * M_PI);
    if (apos_mouse < 0)
        key = TOUCH_LEFT;
    anim_direction(&images->legend, key);
    if (images->game.win_ptr == NULL)
        return (1);

    anim_legend(&images->legend);
    anim_cub3D(images);
    reprint_pos(&images->game);    

    return (0);
}