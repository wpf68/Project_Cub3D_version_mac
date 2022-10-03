/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:35:07 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/03 12:05:38 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void    print_background(t_game *game)
{
    return ;

    
    int x;
    int y;

    x = 0;
    y = -1;
    while (x < game->map.lines)
    {
        while (y++ < game->map.columns - 1)
            draw_square(game, x * 10, y * 10, 10, FLOOR_COLOR);
        y = -1;
        x++;
    }
}