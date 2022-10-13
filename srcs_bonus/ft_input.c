/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/13 15:38:53 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_input_2(t_image *images)
{
    static int time;

    time++;

  //  return(0);
    if (time % 4000 == 0)
    {
        images->cube.nb_sprite += 1;
        images->cube.nb_sprite = images->cube.nb_sprite % NB_ANIME; 
        //ft_input(-1, images);
        anim_cub3D(images);
    }
        




   // (void) images;
  //  printf("*------------  *\n");
   // 
    
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