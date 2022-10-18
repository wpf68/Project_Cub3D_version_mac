/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/17 10:20:44 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_input_2(t_image *images)
{
	static int	time;
	static int	time_2;

	time++;
	time_2++;
	if (time % 1000 == 0)
		anim_cub3d(images);
	if (time % 10000 == 0)
	{
		images->cube.nb_sprite += 1;
		images->cube.nb_sprite = images->cube.nb_sprite % NB_ANIME;
	}
	return (0);
}

int	ft_input(int key, t_image *images)
{
	t_game	*game;

	game = &images->game;
	update(images, key);
	anim_direction(&images->legend, key);
	if (game->win_ptr == NULL)
		return (1);
	anim_legend(&images->legend);
	anim_cub3d(images);
	reprint_pos(game);
	return (0);
}
