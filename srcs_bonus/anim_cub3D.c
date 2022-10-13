/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:03:50 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 15:22:29 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/* https://lodev.org/cgtutor/raycasting.html */


static void ft_anim_hit_wall(t_image *images, t_game *cube)
{
    int ii;
    int jj;

    mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
    cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
    cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
        &cube->img.line_len, &cube->img.endian);
        
    ii = -1;
    while (++ii < CUBE_X)
    {
        jj = -1;
        while (++jj < CUBE_Y)
            img_pix_put(cube, ii, jj, encode_rgb(255, 255, 255));
    }
    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img, 0, 0);
    mlx_do_sync(cube->mlx_ptr);
    usleep(500);

    images->game.map.hit_wall = 0;
}

static void init_floor_sky(t_image *images, t_game *cube)
{
    int i;
    int j;
    
    cube->r.posX = images->game.map.p.pos.x;
    cube->r.posY = images->game.map.p.pos.y;
    cube->r.dirX = -(cos(images->game.map.p.apos));
    cube->r.dirY = -(sin(images->game.map.p.apos));
    cube->r.planeX = sin(images->game.map.p.apos) * 0.66;  // YES
    cube->r.planeY = cos(images->game.map.p.apos) * -0.66;  // YES
    i = 0;
    while (i < CUBE_X)
    {
        j = -1;
        while (++j < CUBE_Y)
        {
            if (j < CUBE_Y / 2)
               img_pix_put(cube, i, j, encode_rgb(0, 0, 0));  // sky
            else
               img_pix_put(cube, i, j, encode_rgb(50, 50, 55));
        }
        i++;
    }
}


int		anim_cub3D(t_image *images)
{
    t_game  *cube;
    char    texture_hit;

    cube = &images->cube;
  
    if (images->game.map.hit_wall)
        ft_anim_hit_wall(images, cube);

    mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
    cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
    cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian);
    init_floor_sky(images, cube);
    cube->r.x = 0;
    while (cube->r.x < CUBE_X)
    {
        ft_init_var_3D_1(cube, cube->r.x);
        ft_calc_dist(images, cube, &texture_hit);
        ft_choice_texture(images, cube, &texture_hit);
    }
    ft_clear_logo_direction(images, cube);
    return (0);
}