/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:30:16 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/11 09:37:19 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_parameters_map(t_game *game)
{
    if (check_map_char(game) == 0)
        error_msg("ERREUR : caractère non défini dans la map !");
    if (check_border_map(game) == 0)
        error_msg("ERREUR : la map est ouverte sur les bords !");
    if (check_zeros(game) == 0)
        error_msg("ERREUR : la map est ouverte à l'interieur !");
    return (0);
}