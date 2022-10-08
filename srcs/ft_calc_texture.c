/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:54:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/08 14:34:52 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_calc_texture(double x_map, int i, int height, t_image *images, int face)
{

   //printf("*********  stop ****-----****\n");
    int     color;
    double  x;
    char    *pixel;

    int x_text;
    int y_text;

  
 
  //  t_img	image;

//	image.mlx_img = mlx_xpm_file_to_image(images->cube.mlx_ptr, "./images_xpm/text_NO.xpm", &image.size.x, &image.size.y);
//	image.addr = mlx_get_data_addr(image.mlx_img,
//			&(image.bpp),
//			&(image.line_len), &(image.endian));

   // x = (int)x_map;
    x = x_map / (1.0 * (images->game.rapport_player)) - (int)(x_map / (1.0 * (images->game.rapport_player)));
  // printf("x_map  =  %f   x = %f\n", x_map, x);


    x_text = (x * images->cube.img_text[face].size.x); 
    y_text = (((i * 1.0) / height) * images->cube.img_text[face].size.y); 
    //y_text = floor( i); 

  //  printf("taille x de la texture = %d    taille y de texture = %d\n", images->legend.img.size.x, images->legend.img.size.y );
  //  printf("x_map = %d   x = %f  x_text = %d  y_text = %d\n", x_map, x, x_text, y_text);


    color = x + height + i + x_text + y_text;
    color = 0;
    pixel = images->cube.img_text[face].addr + (y_text * images->cube.img_text[face].line_len + x_text * (images->cube.img_text[face].bpp / 8));
    color = *(unsigned int *) pixel;



    return (color);

}