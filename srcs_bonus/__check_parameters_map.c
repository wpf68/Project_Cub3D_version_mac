/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:30:16 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/15 16:38:41 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_parameters_map(t_game *game)
{
    if (check_map_char(game) == 0)
        error_msg("Error:\ncaractère non défini dans la map !");
    if (check_border_map(game) == 0)
        error_msg("Error:\nla map est ouverte sur les bords !");
    if (check_zeros(game) == 0)
        error_msg("Error:\nla map est ouverte à l'interieur !");
    return (0);
}