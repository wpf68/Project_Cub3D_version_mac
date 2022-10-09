/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:22 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/09 17:24:10 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main (int argc, char **argv)
{   
    t_image images;

    //images.game.rapport_player = 100;

    

/*
    t_img	image;

	image.mlx_img = mlx_xpm_file_to_image(images->cube.mlx_ptr, "./images_xpm/text_NO.xpm", &image.size.x, &image.size.y);
	image.addr = mlx_get_data_addr(image.mlx_img,
			&(image.bpp),
			&(image.line_len), &(image.endian));
*/

    srand(time(0));

    check_files_map(argc, argv);
    init_map(&images.game, argv[1]);
    init_var_player(&images.game);
    check_nb_player(&images.game);

    init_game(&images.game);


    print_map(&images.game);
//printf("*********  stop ****-----****\n");

    init_legend(&images.game, &images.legend);
    init_cube(&images.game, &images.cube);

    //    images.cube.name_text[0] = ft_strjoin("","./images_xpm/text_NO.xpm");
    //  images.cube.name_text[0] = ft_strjoin("","./images_xpm/Cube3D_2b.xpm");
    // images.cube.name_text[1] = ft_strjoin("","./images_xpm/text_SO.xpm");
    // images.cube.name_text[2] = ft_strjoin("","./images_xpm/text_WE.xpm");
    //   images.cube.name_text[2] = ft_strjoin("","./images_xpm/Cube3D_2b.xpm");

    //  images.cube.name_text[3] = ft_strjoin("","./images_xpm/text_EA.xpm");

/*
    images.cube.name_text[0] = ft_strjoin("","./images_xpm/text__metal+structure+03_d100.xpm");
    images.cube.name_text[1] = ft_strjoin("","./images_xpm/text_Marble-125_1024.xpm");
    images.cube.name_text[2] = ft_strjoin("","./images_xpm/text_Com_BrickFacade0004_1_seamless_S.xpm");
    images.cube.name_text[3] = ft_strjoin("","./images_xpm/txt_laine.xpm");
*/
    images.cube.name_text[4] = ft_strjoin("","./images_xpm/text_star_24.xpm");
    images.cube.name_text[5] = ft_strjoin("","./images_xpm/text_star_23.xpm");

    images.cube.name_text[1] = ft_strjoin("","./images_xpm/text_star_14.xpm");
    images.cube.name_text[2] = ft_strjoin("","./images_xpm/text_star_20.xpm");
    images.cube.name_text[3] = ft_strjoin("","./images_xpm/text_star_19.xpm");
    images.cube.name_text[0] = ft_strjoin("","./images_xpm/text_star_16.xpm");



    ft_init_text(&images.cube); 

    printf("**********  textures OK *******************\n");
    mlx_string_put(images.cube.mlx_ptr, images.cube.win_ptr, 250, 340, 0x00FF00, "       GO");

  
   // mlx_mouse_hide();
    # ifdef __APPLE__
        mlx_mouse_move(images.game.win_ptr, (CUBE_X / 2), CUBE_Y );
    # endif

    mlx_hook(images.game.win_ptr, 2, 1L<<0, *ft_input, &images);
    mlx_hook(images.game.win_ptr, 17, 1L << 17, ft_close, &images);
    mlx_hook(images.game.win_ptr, 6, 1, *move_test, &images);
    mlx_mouse_hook(images.game.win_ptr, *movements_mouse, &images);
   // mlx_hook(images.game.win_ptr, 6, 0, movements_mouse, &images);
    
    mlx_loop(images.game.mlx_ptr);
}