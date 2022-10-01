/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:27:52 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/01 11:10:22 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = game->img.bpp - 8;
    pixel = game->img.addr + (y * game->img.line_len + x * (game->img.bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (game->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (game->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}


void    draw_player(t_game *game, int posx, int posy, int side, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;

    
    if (game->win_ptr == NULL)  //
        return;  //
    while (++i < side - 1)
    {
        while (++j < side - 1)
        {
            if (game->win_ptr != NULL)
                img_pix_put(game, posy + i, posx + j, color);
        }
        j = 0;
    }
}

void draw_player_p(t_game *game, int x, int y)
{
    if (game->map.tab[x][y] == NORTH)
    {
        draw_square(game, x * 10, y * 10, 10, FLOOR_COLOR);
        draw_player(game, x * 10, y * 10, 10, NORTH_COLOR);
    }
    else if (game->map.tab[x][y] == SOUTH)
    {
        draw_square(game, x * 10, y * 10, 10, FLOOR_COLOR);
        draw_player(game, x * 10, y * 10, 10, SOUTH_COLOR);
    }
    else if (game->map.tab[x][y] == EAST)
    {
        draw_square(game, x * 10, y * 10, 10, FLOOR_COLOR);
        draw_player(game, x * 10, y * 10, 10, EAST_COLOR);
    }
    else if  (game->map.tab[x][y] == WEST)
    {
        draw_square(game, x * 10, y * 10, 10, FLOOR_COLOR);
        draw_player(game, x * 10, y * 10, 10, WEST_COLOR);
    }



}
