/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:04:29 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/13 15:51:53 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_text(t_game *cube)
{
    int i;

    i = -1;
    while(++i < 4)
    {
        cube->img_text[i].mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, 
            cube->name_text[i], 
            &cube->img_text[i].size.x, &cube->img_text[i].size.y);
        cube->img_text[i].addr = mlx_get_data_addr(cube->img_text[i].mlx_img,
            &cube->img_text[i].bpp,
            &cube->img_text[i].line_len, &cube->img_text[i].endian);
    }
}