/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:57:36 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/06 09:25:26 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	anim_direction(t_game *legend, int key)
{
    int     wi;
    int     he;

    mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);//
    legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 162, 159); 

    if (key == TOUCH_RIGHT)     //  rotation droite
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/Rotation_droite_vert.xpm", &wi, &he);
    else if (key == TOUCH_LEFT)     //  rotation droite
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/Rotation_gauche_vert.xpm", &wi, &he);
    else if (key == TOUCH_W || key == TOUCH_UP)    //  rotation droite
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/croix_verte_nord.xpm", &wi, &he);
    else if (key == TOUCH_S || key == TOUCH_DOWN)
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/croix_verte_sud.xpm", &wi, &he);
    else if (key == TOUCH_A)      // 1    reculer
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/croix_verte_ouest.xpm", &wi, &he);
    else if (key == TOUCH_D) 
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/croix_verte_est.xpm", &wi, &he);

    
    mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, CUBE_X + 64, 403); // put image finie
    mlx_do_sync(legend->mlx_ptr);
   
}