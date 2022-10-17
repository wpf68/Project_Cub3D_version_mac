/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/17 09:46:42 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_image	images;

	srand(time(0));
	check_files_map(&images.game, argc, argv);
	parse_data_and_map(&images.game, &images.cube);
	parse_data_and_map2(&images.game);
	check_parameters_map(&images.game);
	init_var_player(&images.game);
	check_nb_player(&images.game);
	init_game(&images.game);
	print_map(&images.game);
	init_legend(&images.game, &images.legend);
	init_cube(&images.game, &images.cube);
	ft_init_text(&images.cube);
	mlx_string_put(images.cube.mlx_ptr, images.cube.win_ptr, 250, \
		340, 0x00FF00, "       GO");
	mlx_mouse_move(images.game.win_ptr, (CUBE_X / 2), (CUBE_Y -100));
	mlx_hook(images.game.win_ptr, 2, 1L << 0, *ft_input, &images);
	mlx_hook(images.game.win_ptr, 17, 1L << 17, ft_close, &images);
	mlx_hook(images.game.win_ptr, 6, 1, *move_test, &images);
	mlx_mouse_hook(images.game.win_ptr, *movements_mouse, &images);
	mlx_loop(images.game.mlx_ptr);
}

/*
	# ifdef __APPLE__
        mlx_mouse_move(images.game.win_ptr, (CUBE_X / 2), CUBE_Y -100);
    # endif
	mlx_mouse_move(images.game.mlx_ptr, images.game.win_ptr, (CUBE_X / 2), 
	addindex
	 (CUBE_Y -100));
*/