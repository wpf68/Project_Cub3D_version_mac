/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/01 11:16:55 by pwolff           ###   ########.fr       */
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
    
    mlx_hook(images.game.win_ptr, 2, 1L<<0, *ft_input, &images);
    mlx_loop(images.game.mlx_ptr);
}