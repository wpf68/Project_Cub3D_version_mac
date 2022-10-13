/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:41 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/11 11:20:22 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void     ft_test_size_max_map(t_game *game)
{
    if (game->map.columns * 10 < IMAGE_X - LEGENDE_X && game->map.lines * 
            10 < IMAGE_Y - CUBE_Y)
    {
        game->test_size = 1;
        game->img.mlx_img = mlx_new_image(game->mlx_ptr, (game->map.columns *
            10), (game->map.lines *10));
        game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
            &game->img.line_len, &game->img.endian); 
    }
    else
    {
        game->test_size = 0;
        game->img.mlx_img = mlx_new_image(game->mlx_ptr, IMAGE_X - 
            LEGENDE_X, IMAGE_Y - CUBE_Y);
        game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
                    &game->img.line_len, &game->img.endian); 
    }
}

void    init_game(t_game *game)
{
    int x;
    int y;

    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
        error_msg("pointeur mlx introuvable");

    x = IMAGE_X;
    y = IMAGE_Y;

    game->win_ptr = mlx_new_window(game->mlx_ptr, x, y, "Cub3D");
    if (game->win_ptr == NULL)
    {
        free(game->win_ptr);  
        error_msg("erreur ! fenetre introuvable");
    }
    ft_test_size_max_map(game);
}