/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:51:51 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/27 10:15:15 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_nb_player(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.lines)
    {
        game->map.nb_player += count_char(game->map.tab[i], 'N');
        game->map.nb_player += count_char(game->map.tab[i], 'E');
        game->map.nb_player += count_char(game->map.tab[i], 'S');
        game->map.nb_player += count_char(game->map.tab[i], 'W');
        if (game->map.nb_player == 1)
            init_player_position(game, game->map.tab[i], i);
        i++;   
    }
    if (game->map.nb_player != 1)
        error_msg("ERREUR, aucun ou plus de 1 joueur!");
}