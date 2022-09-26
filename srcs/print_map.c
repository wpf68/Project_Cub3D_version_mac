/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:22:49 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/23 13:07:05 by pwolff           ###   ########.fr       */
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
	while (x < game->map.lines)
	{
		while (y < game->map.columns)
		{
			if (game->map.tab[x][y] == WALL)
				draw_square(game, x * 10, y * 10, 10, WALL_COLOR);
			if (game->map.tab[x][y] == FLOOR)
				draw_square(game, x * 10, y * 10, 10, FLOOR_COLOR);
			if (find_player(game->map.tab[x][y], "NSEW") == 1)
			{
				draw_player_p(game, x, y);
				game->map.tab[(int)floor(game->map.p.pos.y / 10)]\
				[(int)floor(game->map.p.pos.x / 10)] = FLOOR;
			}				
			y++;
		}
		y = 0;
		x++;
	}
		
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0); // put image finie
	return (0);
}
