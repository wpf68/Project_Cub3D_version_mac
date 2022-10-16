/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 07:45:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/16 09:48:37 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_game *game, int posx, int posy, int color)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (game->win_ptr == NULL)
		return ;
	while (++i < 10)
	{
		while (++j < 10)
			img_pix_put(game, posy + i, posx + j, color);
		j = -1;
	}
}
