/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:57:36 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 15:27:53 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	anim_direction_2(t_game *legend, int key)
{
    int     wi;
    int     he;

    if (key == TOUCH_W || key == TOUCH_UP)
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
            "./images_xpm/croix_verte_nord.xpm", &wi, &he);
    else if (key == TOUCH_S || key == TOUCH_DOWN)
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
            "./images_xpm/croix_verte_sud.xpm", &wi, &he);
    else if (key == TOUCH_A)
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
            "./images_xpm/croix_verte_ouest.xpm", &wi, &he);
    else if (key == TOUCH_D) 
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
            "./images_xpm/croix_verte_est.xpm", &wi, &he);
}

void	anim_direction(t_game *legend, int key)
{
    int     wi;
    int     he;

    mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);
    legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 162, 159); 

    if (key == TOUCH_RIGHT)
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
            "./images_xpm/Rotation_droite_vert.xpm", &wi, &he);
    else if (key == TOUCH_LEFT)
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, 
            "./images_xpm/Rotation_gauche_vert.xpm", &wi, &he);
    else
        anim_direction_2(legend, key);

    mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, 
        legend->img.mlx_img, CUBE_X + 64, 403);
    mlx_do_sync(legend->mlx_ptr);
}