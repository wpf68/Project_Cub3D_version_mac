/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:41 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/25 17:48:32 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    init_game(t_game *game)
{
    int x;
    int y;

    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
        error_msg("pointeur mlx introuvable");
 //   game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGTH, "cub3d");

    x = (game->map.columns * 10) + BORDER_X;
    y = (game->map.lines *10) + BORDER_Y;
    if (y < HEIGHT_MINI)
        y = HEIGHT_MINI;
    game->win_ptr = mlx_new_window(game->mlx_ptr, x, y, "Map_Scan");
    if (game->win_ptr == NULL)
    {
        free(game->win_ptr);   //
        error_msg("erreur ! fenetre introuvable");
    }
    game->img.mlx_img = mlx_new_image(game->mlx_ptr, (game->map.columns * 10), (game->map.lines *10)); //
    game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian); //
    //mlx_hook(game->win_ptr, 17, 0, ft_close, 0);
}