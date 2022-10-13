/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:33:12 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/10 15:46:14 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = game->img.bpp - 8;
    pixel = game->img.addr + (y * game->img.line_len + x * 
		(game->img.bpp / 8));
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