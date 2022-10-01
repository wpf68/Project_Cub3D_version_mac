/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:03:50 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/01 16:07:47 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		anim_cub3D(t_image *images)
{
    int     i;
    int     j;
    t_game  *cube;

    cube = &images->cube;


    mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
    cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
    cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian);

    i = 0;
    while (i < CUBE_X)
    {
        j = 0;
        while (j < CUBE_Y)
        {
            if (j < CUBE_Y / 2)
               img_pix_put(cube, i, j, SKY_COLOR);
            else
               img_pix_put(cube, i, j, FLOOR_COLOR);
            j++;
        }
        i++;
    }

    double  pas;
    double  i_d;
    double  angle;
    double  distance;

    double  tmp_x;
    double  tmp_y;
    int     height;

    pas = (ANGLE_OF_VIEW * 2) / CUBE_X;
    i = 0;
    i_d = -(ANGLE_OF_VIEW);
    while (i_d < ANGLE_OF_VIEW)
    {
        angle = images->game.map.p.apos + i_d + M_PI;
     /*   if (angle < 0)
            angle = (2 * M_PI) - angle;
        if (angle > 2 * M_PI) 
            angle = angle - (2 * M_PI);*/
        
        distance = 0;
        tmp_x = images->game.map.p.pos.x;
        tmp_y = images->game.map.p.pos.y;

        while (1)
        {
            if (images->game.map.tab[(int)floor(tmp_y / 10)][(int)floor(tmp_x / 10)] == WALL)
               break;
            tmp_x = tmp_x + (cos(angle) * .1);
            tmp_y = tmp_y + (sin(angle) * .1);
            
          /*
            if (images->game.map.tab[(int)floor(tmp_y / 10)][(int)floor(tmp_x / 10)] == WALL ||
                images->game.map.tab[(int)floor(tmp_y / 10) + 1][(int)floor(tmp_x / 10)] == WALL ||
                images->game.map.tab[(int)floor(tmp_y / 10)][(int)floor(tmp_x / 10) + 1] == WALL ||
                images->game.map.tab[(int)floor(tmp_y / 10) + 1][(int)floor(tmp_x / 10) + 1] == WALL )
                break;*/
            distance = distance + sin(angle);
            
        }
        if (distance < 0)
            distance *= -1;
        printf("distance %f  i = %d  apos = %f angle = %d \n", distance, i, (images->game.map.p.apos * 180 / M_PI), (int)((angle * 180 / M_PI)) % 360);
        height = CUBE_Y - distance;
        if (height < 0)
            height = 0;
            
        if (i < CUBE_X)
        {
            j = 0;
            while (j < height / 2)
            {
               img_pix_put(cube, i, (CUBE_Y / 2) + j, WEST_COLOR);
               img_pix_put(cube, i, (CUBE_Y / 2) - j, WEST_COLOR);
               j++;
            }
            i++;
        }
        else
            break;

        i_d += pas;
    }



    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img, 0, 0);


    return (0);
}