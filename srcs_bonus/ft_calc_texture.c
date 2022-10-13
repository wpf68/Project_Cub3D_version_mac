/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:54:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/13 18:53:09 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_calc_texture(double x_map, int i, t_image *images, int face)
{
    double  x;
    char    *pixel;
    int     x_text;
    int     y_text;
    int     height;

    images->cube.ptr_texture = &images->cube.img_text[face];  // pour gerer l animation


    if (images->cube.r.lineHeight  > CUBE_Y)
      i = i + (images->cube.r.lineHeight - CUBE_Y) / 2;
    height = images->cube.r.lineHeight;
    x = x_map / (1.0 * (images->game.rapport_player)) - (int)(x_map / 
      (1.0 * (images->game.rapport_player)));
    x_text = (x * images->cube.ptr_texture->size.x); 
    y_text = (((i * 1.0) / height) * images->cube.ptr_texture->size.y); 
    pixel = images->cube.ptr_texture->addr + (y_text * 
      images->cube.ptr_texture->line_len + x_text * 
      (images->cube.ptr_texture->bpp / 8));

    return (*(unsigned int *) pixel);
}