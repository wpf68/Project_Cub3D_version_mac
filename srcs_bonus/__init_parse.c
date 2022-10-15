/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:49:19 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/14 09:18:52 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_parse(t_game *game)
{
    game->parse.flag_N = 0;
    game->parse.flag_S = 0;
    game->parse.flag_E = 0;
    game->parse.flag_W = 0;
    game->parse.flag_C = 0;
    game->parse.flag_F = 0;
    game->parse.read_map = 0;
}