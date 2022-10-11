/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_cub3D_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:39:17 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/11 11:04:13 by pwolff           ###   ########.fr       */
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

static void     ft_init_draw(t_image *images, t_game *cube)
{
    if(cube->r.side == 0) 
        cube->r.perpWallDist = (cube->r.sideDistX - cube->r.deltaDistX);
    else          
        cube->r.perpWallDist = (cube->r.sideDistY - cube->r.deltaDistY);

    //Calculate height of line to draw on screen
    cube->r.lineHeight = (int)(CUBE_Y / cube->r.perpWallDist * 
        images->game.rapport_player);  //  * 10

    //calculate lowest and highest pixel to fill in current stripe
    cube->r.drawStart = -cube->r.lineHeight / 2 + CUBE_Y / 2;
    if(cube->r.drawStart < 0) cube->r.drawStart = 0;
    cube->r.drawEnd = cube->r.lineHeight / 2 + CUBE_Y / 2;
    if(cube->r.drawEnd >= CUBE_Y) cube->r.drawEnd = CUBE_Y - 1;
}

static void    ft_test_hit_2(t_image *images, t_game *cube, char *texture_hit)
{
    if(images->game.map.tab[(int)(cube->r.mapY / 
            images->game.rapport_player)][(int)(cube->r.mapX / 
            images->game.rapport_player)] >= WALL &&
            images->game.map.tab[(int)(cube->r.mapY / 
            images->game.rapport_player)][(int)(cube->r.mapX / 
            images->game.rapport_player)] <= '9') 
    {
        *texture_hit = images->game.map.tab[(int)(cube->r.mapY / 
        images->game.rapport_player)][(int)(cube->r.mapX / 
        images->game.rapport_player)];
        cube->r.hit = 1;  // X and Y inverse in tab
    }


}

void    ft_calc_dist(t_image *images, t_game *cube, char *texture_hit)
{
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
        ft_test_hit_2(images, cube, texture_hit);
    }
    ft_init_draw(images, cube);
}
