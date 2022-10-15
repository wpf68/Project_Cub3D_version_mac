/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:01:15 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/26 10:34:25 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int find_player(char p, char *caracters)
{
    int i;

    i = 0; 
    while (caracters[i] != '\0')
    {
        if (p == caracters[i])
        return (1);
    i++;
    }
    return (0);
}