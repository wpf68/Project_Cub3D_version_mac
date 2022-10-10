/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:03:50 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 11:00:32 by pwolff           ###   ########.fr       */
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
    int     i;
    int     x;

    cube = &images->cube;
    
    if (images->game.map.hit_wall)
        ft_anim_hit_wall(images, cube);

    mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
    cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
    cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian);

    init_floor_sky(images, cube);


       // for(int x = 0; x < CUBE_X; x++)
       x = 0;
        while (x < CUBE_X)
        {
            ft_init_var_3D_1(cube, x);
            ft_calc_dist(images, cube, &texture_hit);



            if(cube->r.side == 0) cube->r.perpWallDist = (cube->r.sideDistX - cube->r.deltaDistX);
            else          cube->r.perpWallDist = (cube->r.sideDistY - cube->r.deltaDistY);

            //Calculate height of line to draw on screen
            int lineHeight = (int)(CUBE_Y / cube->r.perpWallDist * images->game.rapport_player);  //  * 10

          //  int pitch = 100;

            //calculate lowest and highest pixel to fill in current stripe
            int drawStart = -lineHeight / 2 + CUBE_Y / 2;
            if(drawStart < 0) drawStart = 0;
            int drawEnd = lineHeight / 2 + CUBE_Y / 2;
            if(drawEnd >= CUBE_Y) drawEnd = CUBE_Y - 1;

            //choose wall color
            int color = WEST_COLOR;
            int index;

            //give x and y sides different brightness
            if(cube->r.side == 0 && texture_hit == WALL) 
            {
                if (cube->r.posX < cube->r.mapX)
                    index = 2;
                else
                    index = 3;
            }
            else if(texture_hit == WALL)
            {
                if (cube->r.posY < cube->r.mapY)
                    index = 0;
                else
                    index = 1;
            }
            else if (texture_hit == '2')
                index = 5;
            else
                index = 4;

            //draw the pixels of the stripe as a vertical line
            //verLine(x, drawStart, drawEnd, color);
         //   printf("side = %d  mapX = %d   mapY = %d \n ", side, mapX, mapY);
            i = drawStart - 1;
            while (++i < drawEnd)
            {
           //     j = -1;
            //    while (++j < 10)
                {
                if (cube->r.side == 1)
                {
                 //   printf("mapx = %d   i = %d, height = %d\n", mapX, i - drawStart, drawEnd - drawStart );
                    color = ft_calc_texture(cube->r.mapX, i - drawStart, drawEnd - drawStart, images, index);
                   // color = ft_calc_texture(sideDistX, i - drawStart, drawEnd - drawStart, images);


                }
                else   
                {
                 //   printf("mapY = %d   i = %d, height = %d\n", mapY, i - drawStart, drawEnd - drawStart );
                   color = ft_calc_texture(cube->r.mapY, i - drawStart, drawEnd - drawStart, images, index);
                  //  color = ft_calc_texture(sideDistY, i - drawStart, drawEnd - drawStart, images);


                }
                img_pix_put(cube, x, i, color);




                }
                
            }
               


            x += 1;
        }



   // printf("x = %f y = %f  direct x = %f  direct y = %f\n", posX, posY, dirX, dirY);
   // printf(" ***********  planeX = %f planeY = %f\n", planeX, planeY);







    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img, 0, 0);

    int     wi;
    int     he;
    t_game  *legend;

    legend = &images->legend;

  //  if (key == TOUCH_RIGHT)     //  rotation droite
    {
        mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);//

        legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 162, 159); 
        legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, "./images_xpm/fleches_bleues_162_159.xpm", &wi, &he);
        mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, legend->img.mlx_img, CUBE_X + 64, 403); // put image finie

    }



    return (0);

}


/*

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

        
        distance = 0;
        tmp_x = images->game.map.p.pos.x;
        tmp_y = images->game.map.p.pos.y;

        while (1)
        {
            if (images->game.map.tab[(int)floor(tmp_y / 10)][(int)floor(tmp_x / 10)] == WALL)
               break;
            tmp_x = tmp_x + (cos(angle) * .1);
            tmp_y = tmp_y + (sin(angle) * .1);
            

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

*/
