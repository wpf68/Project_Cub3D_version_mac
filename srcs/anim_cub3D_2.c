/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:39:17 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 11:01:14 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void ft_check_wall(t_game *cube)
{
    if(cube->r.rayDirX < 0)
    {
        cube->r.stepX = -(1);
        cube->r.sideDistX = (cube->r.posX - cube->r.mapX) * cube->r.deltaDistX;
    }
    else
    {
        cube->r.stepX = 1;
        cube->r.sideDistX = (cube->r.mapX + 1.0 - cube->r.posX) * cube->r.deltaDistX;
    }
    if(cube->r.rayDirY < 0)
    {
        cube->r.stepY = -(1);
        cube->r.sideDistY = (cube->r.posY - cube->r.mapY) * cube->r.deltaDistY;
    }
    else
    {
        cube->r.stepY = 1;
        cube->r.sideDistY = (cube->r.mapY + 1.0 - cube->r.posY) * cube->r.deltaDistY;
    }

}

void    ft_init_var_3D_1(t_game *cube, int x)
{
    cube->r.cameraX = 2.0 * x / (double)CUBE_X - 1; //x-coordinate in camera space

    cube->r.rayDirX = cube->r.dirX + cube->r.planeX * cube->r.cameraX;
    cube->r.rayDirY = cube->r.dirY + cube->r.planeY * cube->r.cameraX;
    cube->r.mapX = (int)(cube->r.posX);
    cube->r.mapY = (int)(cube->r.posY);

    //length of ray from current position to next x or y-side

    if (cube->r.rayDirX == 0)
       cube->r.deltaDistX =  1e30;
    else
       cube->r.deltaDistX = fabs(1 / cube->r.rayDirX);
    
    if (cube->r.rayDirY == 0)
         cube->r.deltaDistY = 1e30;
    else     
         cube->r.deltaDistY = fabs(1 / cube->r.rayDirY);
    cube->r.hit = 0;
    ft_check_wall(cube);
}

void    ft_calc_dist(t_image *images, t_game *cube, char *texture_hit)
{
    //perform DDA
    while(cube->r.hit == 0)
    {
        if(cube->r.sideDistX < cube->r.sideDistY)
        {
            cube->r.sideDistX += cube->r.deltaDistX;
            cube->r.mapX += cube->r.stepX;
            cube->r.side = 0;
        }
        else
        {
            cube->r.sideDistY += cube->r.deltaDistY;
            cube->r.mapY += cube->r.stepY;
            cube->r.side = 1;
        }

        if(images->game.map.tab[(int)(cube->r.mapY / images->game.rapport_player)][(int)(cube->r.mapX / images->game.rapport_player)] >= WALL &&
                images->game.map.tab[(int)(cube->r.mapY / images->game.rapport_player)][(int)(cube->r.mapX / images->game.rapport_player)] <= '9') 
        {
            *texture_hit = images->game.map.tab[(int)(cube->r.mapY / images->game.rapport_player)][(int)(cube->r.mapX / images->game.rapport_player)];
            cube->r.hit = 1;  // X and Y inverse in tab
        }
    }


}
