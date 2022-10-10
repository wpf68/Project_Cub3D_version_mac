/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:22:49 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/10 09:37:36 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	if (game->win_ptr == NULL) // sécurité
		return (1);
	if (game->test_size == 0)
	{
		
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, CUBE_Y); // put image finie

		mlx_string_put(game->mlx_ptr, game->win_ptr, 100 , CUBE_Y + 100, encode_rgb(0, 255, 0), "*** TOO LARGE *** ");

		return (1);
	}
	
	while (x < game->map.lines)
	{
		while (y < game->map.columns)
		{
			if (game->map.tab[x][y] >= WALL && game->map.tab[x][y] <= '9')   //  test
			{
				int	wi;
				int	he;

				game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, "./images_xpm/wall.xpm", &wi, &he);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, y * 10, x * 10 + CUBE_Y); // put image finie
				//draw_square(game, x * 10, y * 10, 10, WALL_COLOR);

			}			
			else
				draw_square(game, x * 10, y * 10, 10, WEST_COLOR);

			if (find_player(game->map.tab[x][y], "NSEW") == 1)
			{
				draw_player_p(game, x, y);
				game->map.tab[(int)floor(game->map.p.pos.y / game->rapport_player)]\
				[(int)floor(game->map.p.pos.x / game->rapport_player)] = FLOOR;
			}				
			y++;
		}
		y = 0;
		x++;
	}
		
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, CUBE_Y); // put image finie
	return (0);
}
