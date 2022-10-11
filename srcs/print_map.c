/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:22:49 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/11 11:30:05 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_test_size_map(t_game *game)
{
	//return (0); /// 
	if (game->win_ptr == NULL)
		return (1);
	if (game->test_size == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
			game->img.mlx_img, 0, CUBE_Y);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100 , CUBE_Y + 100, 
			encode_rgb(0, 255, 0), "*** TOO LARGE *** ");
		return (0);
	}
	return (0);
}

static void	ft_put_wall_player(t_game *game, int x, int y)
{
	int	wi;
	int	he;

	if (game->map.tab[x][y] >= WALL && game->map.tab[x][y] <= '9' && (game->test_size))
	{
		game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, 
			"./images_xpm/wall.xpm", &wi, &he);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
			game->img.mlx_img, y * 10, x * 10 + CUBE_Y);
	}			
	if (find_player(game->map.tab[x][y], "NSEW") == 1)
	{
		if (game->test_size)
			draw_player_p(game, x, y);
		game->map.tab[(int)floor(game->map.p.pos.y / 
			game->rapport_player)] [(int)floor(game->map.p.pos.x / 
			game->rapport_player)] = FLOOR;
	}	
}

int	print_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	if (ft_test_size_map(game))
		return (1);

	while (++x < game->map.lines)
	{
		y = -1;	
		while (++y < game->map.columns)
			ft_put_wall_player(game, x, y);
	}
	if (game->test_size)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img,
			0, CUBE_Y);
	return (0);
}
