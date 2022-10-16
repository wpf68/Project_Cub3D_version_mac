/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:33:12 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/16 10:30:30 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	img_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = game->img.bpp - 8;
	pixel = game->img.addr + (y * game->img.line_len + x * \
		(game->img.bpp / 8));
	while (i >= 0)
	{
		if (game->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (game->img.bpp - 8 - i)) & 0xFF;
				i -= 8;
	}
}
