/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/29 10:00:07 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_input(int key, t_image *images)
{
    t_game *game;

    game = &images->game;
   // game = &images.game;
  //  mlx_clear_window(game->mlx_ptr, game->win_ptr);
    update(images, key);
    if (game->win_ptr == NULL)
        return (1);
    ft_printf("key --> %d\n", key);


    reprint_pos(game);
    return (0);
}