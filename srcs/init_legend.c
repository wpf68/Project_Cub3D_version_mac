/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_legend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:04:52 by pwolff            #+#    #+#             */
/*   Updated: 2022/10/17 08:43:23 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_legend(t_game *game, t_game *legend)
{
	int	wi;
	int	he;

	legend->mlx_ptr = game->mlx_ptr;
	legend->win_ptr = game->win_ptr;
	legend->map.lines = game->map.lines;
	legend->map.columns = game->map.columns;
	legend->map.move = 0;
	legend->apos_game = &(game->map.p.apos);
	legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, LEGENDE_X, LEGENDE_Y);
	legend->img.addr = mlx_get_data_addr(legend->img.mlx_img, &legend->img.bpp \
		, &legend->img.line_len, &legend->img.endian);
	legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, \
		"./images_xpm/Cube3D_1b.xpm", &wi, &he);
	mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, \
		legend->img.mlx_img, CUBE_X, 0);
}

void	draw_circle_bis(t_game *image, int r, int color)
{
	double	cos_x;
	double	sin_y;
	double	i;

	i = 0;
	while (i < 2 * 3.141592)
	{
		cos_x = cos(i) * (r);
		sin_y = sin(i) * (r);
		img_pix_put(image, image->r.dir_x + cos_x, \
		image->r.dir_y + sin_y, color);
		i += 0.2;
	}
}

void	draw_circle(t_game *image, int r, int color)
{
	int	i;

	image->r.dir_x = 60;
	image->r.dir_y = 56;
	i = r - 3;
	while (i < (r + 4))
	{
		draw_circle_bis(image, i, color);
		i++;
	}
	image->r.dir_x = image->r.dir_x - cos(*image->apos_game) * r;
	image->r.dir_y = image->r.dir_y - sin(*image->apos_game) * r;
	i = -1;
	while (++i < 3)
		draw_circle_bis(image, i, 0x0050D317);
	while (++i < 5)
		draw_circle_bis(image, i, 0x002F7E0D);
}

static void	ft_anim_legend_2(t_game *legend, char *itoa_angle, char *temp)
{
	int	angle;

	angle = (*legend->apos_game) * 180 / M_PI;
	if (angle < 0)
		angle = angle * (-1) + 180;
	angle %= 360;
	itoa_angle = ft_itoa(angle);
	if (ft_strlen(itoa_angle) < 3)
	{
		temp = itoa_angle;
		itoa_angle = ft_strjoin("0", temp);
		free(temp);
	}
	if (ft_strlen(itoa_angle) < 3)
	{
		temp = itoa_angle;
		itoa_angle = ft_strjoin("0", temp);
		free(temp);
	}
	mlx_string_put(legend->mlx_ptr, legend->win_ptr, CUBE_X - 5 + \
		DEGREE_X2, DEGREE_Y2, SOUTH_COLOR, itoa_angle);
	free(itoa_angle);
}

int	anim_legend(t_game *legend)
{
	char	*itoa_angle;
	char	*temp;

	temp = NULL;
	itoa_angle = NULL;
	mlx_destroy_image(legend->mlx_ptr, legend->img.mlx_img);
	legend->img.mlx_img = mlx_new_image(legend->mlx_ptr, 121, 113);
	legend->img.mlx_img = mlx_xpm_file_to_image(legend->mlx_ptr, \
		"./images_xpm/Cube3D_2b.xpm", &legend->img.size.x, \
		&legend->img.size.y);
	legend->img.addr = mlx_get_data_addr(legend->img.mlx_img, \
		&legend->img.bpp, &legend->img.line_len, &legend->img.endian);
	draw_circle(legend, 48, 0x00DF9D00);
	mlx_put_image_to_window(legend->mlx_ptr, legend->win_ptr, \
		legend->img.mlx_img, CUBE_X + 90, 204);
	ft_anim_legend_2(legend, itoa_angle, temp);
	return (0);
}
