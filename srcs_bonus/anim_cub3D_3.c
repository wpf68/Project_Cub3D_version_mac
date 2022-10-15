/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:52:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/15 14:24:03 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void ft_choice_pixel_color(t_image *images, t_game *cube)
{
    int color;
    int i;

    i = cube->r.drawStart - 1;
    while (++i < cube->r.drawEnd)
    {
        if (cube->r.side == 1)
            color = ft_calc_texture(cube->r.mapX, i - cube->r.drawStart, 
                images, cube->r.index);
        else   
            color = ft_calc_texture(cube->r.mapY, i - cube->r.drawStart, 
                images, cube->r.index);
        img_pix_put(cube, cube->r.x, i, color);
    }
    cube->r.x += 1;
}

void    ft_choice_texture(t_image *images, t_game *cube, char *texture_hit)
{
    static int  anime;

    anime++;
    if(cube->r.side == 0 && *texture_hit == WALL) 
    {
        if (cube->r.posX < cube->r.mapX)
            cube->r.index = 2;
        else
            cube->r.index = 3;
    }
    else if(*texture_hit == WALL)
    {
        if (cube->r.posY < cube->r.mapY)
            cube->r.index = 0;
        else
            cube->r.index = 1;
    }
    else if (*texture_hit == '2')
        cube->r.index = 5;
    else if (*texture_hit == '3')
        cube->r.index = 4;
    else if (*texture_hit == '4')
    {
        //  printf("anime = %d\n")
        cube->r.index = 6;
        if (anime % 8000 > 2000)
            cube->r.index = 7;
    }
    else if (*texture_hit == '5')
    {
        //  printf("anime = %d\n")
        cube->r.index = 8;
        if (anime % 2100 > 700 && anime % 2100 < 1400)
            cube->r.index = 9;
        if (anime % 2100 >= 1400)
            cube->r.index = 10;
    }
    
        
    ft_choice_pixel_color(images, cube);
}

void    ft_clear_logo_direction(t_image *images, t_game *cube)
{
    int     wi;
    int     he;
    t_game  *legend;

    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, 
        cube->img.mlx_img, 0, 0);
    legend = &images->legend;
    mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);//
    legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 162, 159); 
    legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
        "./images_xpm/fleches_bleues_162_159.xpm", &wi, &he);
    mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, 
        CUBE_X + 64, 403);
}
