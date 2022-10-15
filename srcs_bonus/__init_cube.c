/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:06:00 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/13 14:26:52 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void ft_border(t_game *cube)
{
    int i;

    i = 0;
    while (i < CUBE_Y - 10)
    {
      draw_square(cube, i, 0, 10, WALL_COLOR);
      draw_square(cube, i, CUBE_X - 10, 10, WALL_COLOR);
      i += 10;
    }
     i = 0;
    while (i < CUBE_X)
    {
    	draw_square(cube, 0, i, 10, WALL_COLOR);
      draw_square(cube, CUBE_Y - 10, i, 10, WALL_COLOR);
      i += 10;
    }
}

void    init_cube(t_game *game, t_game *cube)
{
    cube->mlx_ptr = game->mlx_ptr;
    cube->win_ptr = game->win_ptr;

    cube->img.mlx_img = mlx_new_image(cube->mlx_ptr, CUBE_X, CUBE_Y); 
    cube->img.addr = mlx_get_data_addr(cube->img.mlx_img, &cube->img.bpp,
			&cube->img.line_len, &cube->img.endian); //
    ft_border(cube);
    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img.mlx_img,
       0, 0); 
    mlx_string_put(cube->mlx_ptr, cube->win_ptr, 250, 300, 0x00FF00, 
      "***  VIEW 3D  ***");
    mlx_string_put(cube->mlx_ptr, cube->win_ptr, 250, 320, 0x00FF00, 
      "    Waiting");
}