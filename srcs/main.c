/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/06 10:01:57 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main (int argc, char **argv)
{   
    t_image images;

    srand(time(0));

    check_files_map(argc, argv);
    init_map(&images.game, argv[1]);
    init_var_player(&images.game);
    check_nb_player(&images.game);

    init_game(&images.game);
    print_map(&images.game);
    init_legend(&images.game, &images.legend);
    init_cube(&images.game, &images.cube);

    mlx_mouse_hook(images.game.win_ptr, *movements_mouse, &images);
   // mlx_mouse_hide();
    mlx_mouse_move(images.game.win_ptr, CUBE_X / 2, CUBE_Y );
    mlx_hook(images.game.win_ptr, 2, 1L<<0, *ft_input, &images);
    mlx_hook(images.game.win_ptr, 17, 1L << 17, ft_close, &images);
    mlx_hook(images.game.win_ptr, 6, 1, *move_test, &images);
    
   // mlx_hook(images.game.win_ptr, 6, 0, movements_mouse, &images);
    
    mlx_loop(images.game.mlx_ptr);
}