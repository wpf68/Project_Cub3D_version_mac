/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:03:50 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/07 11:29:47 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/* https://lodev.org/cgtutor/raycasting.html */

int		anim_cub3D(t_image *images)
{
    t_game  *cube;
   int     ii;
    int     jj;

    cube = &images->cube;

    if (images->game.map.hit_wall)
    {
   //     ii = 0;
    //    while (ii++ < 10)
       /* {
            t_game  temp;

            temp.img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
            temp.img.addr = mlx_get_data_addr(temp.img.mlx_img, &temp.img.bpp,
			&temp.img.line_len, &temp.img.endian);

            ii = 0;
            while (ii < CUBE_X)
            {
                jj = 0;
                while (jj < CUBE_Y)
                {
                    if (jj < CUBE_Y / 2)
                    img_pix_put(&temp, ii, jj, encode_rgb(100, 100, 255));
                    else
                    img_pix_put(&temp, ii, jj, FLOOR_COLOR);
                    jj++;
                }
                ii++;
            }*/
            mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
            cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
            cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
		    	&cube->img.line_len, &cube->img.endian);





               
            ii = 0;
            while (ii < CUBE_X)
            {
                jj = 0;
                while (jj < CUBE_Y)
                {
                 //   if (jj < CUBE_Y)
                        img_pix_put(cube, ii, jj, encode_rgb(255, 255, 255));
                 //   else
                 //       img_pix_put(cube, ii, jj, encode_rgb(0 ,0 ,0));
                    jj++;
                }
                ii++;
            }
            ii = 0;
            while (ii < CUBE_X / 2)
            {
                draw_circle_bis(cube, CUBE_X / 2, CUBE_Y / 2, ii, (ii % 3) * 255);
                ii += 10;
            }


/*

            int			wi;
            int			he;
            cube->img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, "./images_xpm/boom_black_600_600.xpm", &wi, &he);
            mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img, 0, 0); // put image finie
*/


           //  mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
         //   cube = &temp;
            mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img, 0, 0);
            mlx_do_sync(cube->mlx_ptr);
           usleep(500);
         //   ii = 0;

            

        //    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, &temp.img.mlx_img, 0, 0);
          //  printf("**********  HIT WALL ************\n");
          //  usleep(100);

           images->game.map.hit_wall = 0;

        }



    mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
    cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
    cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian);

    // Position player
    double posX = images->game.map.p.pos.x;
    double posY = images->game.map.p.pos.y;

    // vector direction
  //  images->game.map.p.apos = 0;
    double dirX = -(cos(images->game.map.p.apos));
    double dirY = -(sin(images->game.map.p.apos));
  //  double dirX = -1, dirY = 0; //initial direction vector

   // printf("x = %f y = %f  direct x = %f  direct y = %f\n", posX, posY, dirX, dirY);
   // return (0);


    // camera plane

    double  planeX; 
    double  planeY;

    planeX = sin(images->game.map.p.apos) * 0.66;  // YES
    planeY = cos(images->game.map.p.apos) * -0.66;  // YES

    /*
    if (images->game.map.p.apos >= 3 * M_PI /4 && images->game.map.p.apos < 5 * M_PI / 4)
    {
        planeX = 0;
        planeY = 0.66;
    }
    if (images->game.map.p.apos >= 7 * M_PI /4 || images->game.map.p.apos < M_PI / 4)
    {
        planeX = 0;
        planeY = -0.66;
    }
    if (images->game.map.p.apos >= M_PI /4 && images->game.map.p.apos < 3 * M_PI / 4)
    {
        planeX = 0.66;
        planeY = 0;
    }
    if (images->game.map.p.apos >= 5 * M_PI /4 && images->game.map.p.apos < 7 * M_PI / 4)
    {
        planeX = -0.66;
        planeY = 0;
    }
    
*/

 //  double  planeX = 0; 
  //  double  planeY = 0.66;
   // if (images->game.map.p.apos < M_PI / 2 || images->game.map.p.apos > 3 * M_PI / 2)
   //         planeY = -0.66;

    // floor and sky
    int i;
    int j;
    i = 0;
    while (i < CUBE_X)
    {
        j = 0;
        while (j < CUBE_Y)
        {
            if (j < CUBE_Y / 2)
               img_pix_put(cube, i, j, encode_rgb(100, 100, 255));
            else
               img_pix_put(cube, i, j, FLOOR_COLOR);
            j++;
        }
        i++;
    }


  //  while(!done())
    {
        for(int x = 0; x < CUBE_X; x++)
        {

            //calculate ray position and direction
       //     double cameraX = 2 * x / (double)CUBE_X - 1; //x-coordinate in camera space
            double cameraX = 2 * x / (double)CUBE_X - 1; //x-coordinate in camera space

            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;
            //which box of the map we're in
            int mapX = (int)(posX);
            int mapY = (int)(posY);

            //length of ray from current position to next x or y-side
            double sideDistX;
            double sideDistY;

            double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

            double perpWallDist;

                  //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;

            int hit = 0; //was there a wall hit?
            int side; //was a NS or a EW wall hit?




            //calculate step and initial sideDist
            if(rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if(rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }



            //perform DDA
            while(hit == 0)
            {
                //jump to next map square, either in x-direction, or in y-direction
                if(sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                //Check if ray has hit a wall
              //  printf(" ***********  mapX = %f mapY = %f\n", (double)mapX / 10, (double)mapY / 10);
             //   if (mapX / 10 > images->game.map.columns || mapY / 10 > images->game.map.lines)
                //    break;
                if (mapY / 10 < 0)
                    mapY = 0;
                if (mapX / 10 < 0)
                    mapX = 0;
           //     printf(" ---------  mapX = %d mapY = %d\n", mapX / 10, mapY / 10);

                if(images->game.map.tab[mapY / 10][mapX / 10] == WALL) hit = 1;  // X and Y inverse in tab
            }
         //   printf(" ---------  mapX = %d mapY = %d\n", mapX / 10, mapY / 10);



            if(side == 0) perpWallDist = (sideDistX - deltaDistX);
            else          perpWallDist = (sideDistY - deltaDistY);

            //Calculate height of line to draw on screen
            int lineHeight = (int)(CUBE_Y / perpWallDist * 10);  //  * 10

            //calculate lowest and highest pixel to fill in current stripe
            int drawStart = -lineHeight / 2 + CUBE_Y / 2;
            if(drawStart < 0) drawStart = 0;
            int drawEnd = lineHeight / 2 + CUBE_Y / 2;
            if(drawEnd >= CUBE_Y) drawEnd = CUBE_Y - 1;

            //choose wall color
            int color = WEST_COLOR;

            //give x and y sides different brightness
            if(side == 0) 
            {
                if (posX < mapX)
                    color = WEST_COLOR;
                else
                    color = EAST_COLOR;
            }
            else
            {
                if (posY < mapY)
                    color = NORTH_COLOR;
                else
                    color = SOUTH_COLOR;
            }

            //draw the pixels of the stripe as a vertical line
            //verLine(x, drawStart, drawEnd, color);
         //   printf("side = %d  mapX = %d   mapY = %d \n ", side, mapX, mapY);
            i = drawStart - 1;
            while (++i < drawEnd)
            {
                if (side == 1)
                {
                 //   printf("mapx = %d   i = %d, height = %d\n", mapX, i - drawStart, drawEnd - drawStart );
                    color = ft_calc_texture(mapX, i - drawStart, drawEnd - drawStart, images);


                }
                else   
                {
                 //   printf("mapY = %d   i = %d, height = %d\n", mapY, i - drawStart, drawEnd - drawStart );
                    color = ft_calc_texture(mapY, i - drawStart, drawEnd - drawStart, images);


                }
                img_pix_put(cube, x, i, color);
            }
               



        }


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
