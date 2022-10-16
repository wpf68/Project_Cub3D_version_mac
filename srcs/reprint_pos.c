/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:09:37 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/16 10:49:15 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

static void	ft_color_gradient2(int *orientation, int *int_color, int *x)
{
	if (*orientation >= (3926990) && *orientation < (5497786))
	{
		*x = (((3 * 3141592 / 2) - *orientation) / 6160) * 1;
		if (*x < 0)
			*x *= -1;
		*int_color = encode_rgb(0, 255 - *x, 0);
	}
	else
	{
		if (*orientation < 3141592 / 4)
			*x = *orientation / 6160;
		else
			*x = (((3141592 * 2) - *orientation) / 6160) * 2;
		*int_color = encode_rgb(255, 255, *x);
	}
}

static void	ft_color_gradient(int *orientation, int *int_color, int *x)
{
	if (*orientation >= (3141592 / 4) && *orientation < (2356194))
	{
		*x = (((3141592 / 2) - *orientation) / 6160) * 1;
		if (*x < 0)
			*x *= -1;
		*int_color = encode_rgb(255 - *x, 0, 0);
	}
	else if (*orientation >= (2356194) && *orientation < (3926990))
	{
		*x = (((3141592) - *orientation) / 6160) * 1;
		if (*x < 0)
			*x *= -1;
		*int_color = encode_rgb(0, 0, 255 - *x);
	}
	else
		ft_color_gradient2(orientation, int_color, x);
}

static void	ft_destroy_and_init(t_game *game, int *orientation, int *int_color)
{
	int	x;

	x = 0;
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, 10, 10);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	*orientation = (int)(game->map.p.apos * 1000000) % (3141592 * 2);
	if (*orientation < 0)
		*orientation = (3141592 * 2) + *orientation;
	ft_color_gradient(orientation, int_color, &x);
}

int	reprint_pos(t_game *game)
{
	int	int_color;
	int	orientation;

	if (game->test_size == 0)
		return (0);
	ft_destroy_and_init(game, &orientation, &int_color);
	draw_player(game, 0, 0, int_color);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, \
		game->map.p.pos.x * 10 / game->rapport_player, game->map.p.pos.y * \
		10 / game->rapport_player + CUBE_Y);
	return (0);
}
