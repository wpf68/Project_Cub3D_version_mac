/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:49:19 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/16 10:02:22 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_parse(t_game *game)
{
	game->parse.flag_N = 0;
	game->parse.flag_S = 0;
	game->parse.flag_E = 0;
	game->parse.flag_W = 0;
	game->parse.flag_C = 0;
	game->parse.flag_F = 0;
	game->parse.read_map = 0;
}
