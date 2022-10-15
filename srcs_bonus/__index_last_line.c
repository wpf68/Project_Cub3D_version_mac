/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_last_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:37:10 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/12 12:49:20 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int index_last_line(t_game *game)
{
    int i;
    int size;

    i = 0;
    while (game->map.tab[i])
        i++;
    size = i;
    return (size);
}