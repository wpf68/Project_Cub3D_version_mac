/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:09:37 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/10 09:47:11 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}


int    reprint_pos(t_game *game)
{
    int x;
 //   int y;
	int	int_color;  // couleur en fonction de l'orientation du player

    x = 0;


	if (game->test_size == 0)
		return (0);
	
/*	draw_player(game, 0, 0, 10, 0);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, game->map.p.pos.x * 10 / game->rapport_player,
		 game->map.p.pos.y * 10 / game->rapport_player + CUBE_Y);
	mlx_do_sync(game->mlx_ptr);*/
		 
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);//
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, 10, 10); //
    game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian); //











	//  Couleur du joueur en fonction de son orientation  //
	int	orientation;

	orientation = (int)(game->map.p.apos * 1000000) % (3141592 * 2);
	if (orientation < 0)
		orientation = (3141592 * 2) + orientation;
	
	if (orientation >= (3141592 / 4) && orientation < (3 * 3141592 / 4))
	{
		x = (((3141592 / 2) - orientation) / 6160) * 1;
		if (x < 0)
			x*= -1;
		int_color = encode_rgb(255 - x, 0, 0);   //  red  - NORTH  -  16711680
	}
	else if (orientation >= (3 * 3141592 / 4) && orientation < (5 * 3141592 / 4))
	{
		x = (((3141592) - orientation) / 6160) * 1;
		if (x < 0)
			x*= -1;
		int_color = encode_rgb(0, 0, 255 - x);  // blue  - EAST  - 255
	}
	else if (orientation >= (5 * 3141592 / 4) && orientation < (7 * 3141592 / 4))
	{
		x = (((3 * 3141592 / 2) - orientation) / 6160) * 1;
		if (x < 0)
			x*= -1;
		int_color = encode_rgb(0, 255 - x, 0); // green  - SOUTH  -  65280
	}
	else
	{
		if (orientation < 3141592 / 4)
			x = orientation / 6160;
		else
			x = (((3141592 * 2) - orientation) / 6160) * 2;
		int_color = encode_rgb(255, 255, x); // 16776960 - // yellow - WEST 
	}

	//printf("apos = %f  Orientation = %d  --  int_color = %d\n", game->map.p.apos, orientation, int_color); //
//	draw_player(game, 0, 0, 10, int_color);
		
//	printf("color = %d\n", int_color);
	//int_color = WEST_COLOR;
	draw_player(game, 0, 0, 10, int_color);
		
	//draw_player(game, game->map.p.pos.y, game->map.p.pos.x, 10, int_color);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, game->map.p.pos.x * 10 / game->rapport_player,
		 game->map.p.pos.y * 10 / game->rapport_player + CUBE_Y); // put image finie

	return (0);
}