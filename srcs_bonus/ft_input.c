/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/11 11:06:53 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_input_2(t_image *images)
{
    ft_input(TOUCH_W, images);
    return (0);
}

int ft_input(int key, t_image *images)
{
    t_game *game;

    game = &images->game;   
    update(images, key); // movements
    anim_direction(&images->legend, key);
    if (game->win_ptr == NULL)
        return (1);
    anim_legend(&images->legend);
    anim_cub3D(images);
    reprint_pos(game);
    return (0);
}