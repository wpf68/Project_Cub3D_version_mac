/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/15 14:18:14 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_input_2(t_image *images)
{
    static int time;
    static int time_2; // à voir

    time++;
    time_2++;  // à voir

  //  return(0);
    if (time % 1000 == 0)
    {
        
        
        //ft_input(-1, images);
        anim_cub3d(images);
    }
    if (time % 10000 == 0)
    {
        images->cube.nb_sprite += 1;
        images->cube.nb_sprite = images->cube.nb_sprite % NB_ANIME; 
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
    anim_cub3d(images);
    reprint_pos(game);
    return (0);
}