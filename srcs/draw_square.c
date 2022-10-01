/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 07:45:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/01 11:10:59 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_square(t_game *game, int posx, int posy, int side, int color)
{
    int i;
    int j;

    i = -1;
    j = -1;

    
    if (game->win_ptr == NULL)  //
        return;  //
    while (++i < side)
    {
        while (++j < side)
            img_pix_put(game, posy + i, posx + j, color);
        j = -1;
    }
}