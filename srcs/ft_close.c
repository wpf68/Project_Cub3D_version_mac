/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:33:56 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/10 08:49:58 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_close(t_image *image)
{
    t_game  *game;
    int     i;
    
    game = &image->game;

    mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
    mlx_destroy_image(image->legend.mlx_ptr, image->legend.img.mlx_img);
    mlx_destroy_image(image->cube.mlx_ptr, image->cube.img.mlx_img);

    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);

    i = -1;
    while (image->game.map.tab[++i])
        free(image->game.map.tab[i]);

    free(image->game.map.tab);

    i = -1;
    while(++i < NB_TEXTURES)
        free(image->cube.name_text[i]);

    exit (0);
}