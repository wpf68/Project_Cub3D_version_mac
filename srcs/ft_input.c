/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:37:57 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/23 13:22:10 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_input(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
  //  mlx_clear_window(game->mlx_ptr, game->win_ptr);
    update(game, key);
    if (game->win_ptr == NULL)
        return (1);
    ft_printf("key --> %d\n", key);


    reprint_pos(game);
    return (0);
}