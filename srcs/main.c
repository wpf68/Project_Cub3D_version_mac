/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/09/26 15:06:12 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main (int argc, char **argv)
{   
    t_game game;
    t_game  legend;  //

    srand(time(0));

    check_files_map(argc, argv);
    init_map(&game, argv[1]);
    init_var_player(&game);
    check_nb_player(&game);
    init_game(&game); // map
  
    print_map(&game);   // à supprimer et à remplacer par mlx_loop_hook -->
   // mlx_loop_hook(game.mlx_ptr, *print_map, &game);//

    init_legend(&game, &legend); // 
    

    mlx_loop_hook(legend.mlx_ptr, *anim_legend, &legend);//
    mlx_hook(game.win_ptr, 2, 1L<<0, *ft_input, &game);
    mlx_hook(game.win_ptr, 3, 1L<<1, *ft_input, &game);
    mlx_loop(game.mlx_ptr);

    // nettoyage --
    mlx_destroy_image(game.mlx_ptr, game.img.mlx_img);
    mlx_destroy_image(legend.mlx_ptr, legend.img.mlx_img);  // problémes ******

	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
    //mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);

}