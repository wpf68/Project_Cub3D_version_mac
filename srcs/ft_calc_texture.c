/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:54:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/07 11:50:23 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_calc_texture(int x_map, int i, int height, t_image *images)
{
    int     color;
    double  x;
    char    *pixel;

    int x_text;
    int y_text;

    (void) images;
  //  t_img	image;

//	image.mlx_img = mlx_xpm_file_to_image(images->cube.mlx_ptr, "./images_xpm/text_NO.xpm", &image.size.x, &image.size.y);
//	image.addr = mlx_get_data_addr(image.mlx_img,
//			&(image.bpp),
//			&(image.line_len), &(image.endian));

    x = x_map / 10.0;
    x = x - floor(x_map / 10.0);

    x_text = (x * images->legend.img.size.x); 
    y_text = (((i * 1.0) / height) * images->legend.img.size.y); 
    //y_text = floor( i); 

  //  printf("taille x de la texture = %d    taille y de texture = %d\n", images->legend.img.size.x, images->legend.img.size.y );
  //  printf("x_map = %d   x = %f  x_text = %d  y_text = %d\n", x_map, x, x_text, y_text);


    color = x + height + i + x_text + y_text;
    color = 0;
    pixel = images->legend.img.addr + (y_text * images->legend.img.line_len + x_text * (images->legend.img.bpp / 8));
    color = *(unsigned int *) pixel;



    return (color);

}