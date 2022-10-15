/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:15:29 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/15 08:58:07 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int parse_flag(t_game *game)
{
    if (game->parse.flag_N == 0 || game->parse.flag_S == 0
        || game->parse.flag_E == 0 || game->parse.flag_E == 0
        || game->parse.flag_C == 0 || game->parse.flag_F == 0)
        return (0);
    return (1);
}

int empty_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            i++;
        else
            return (0);
    }
    return (1);
}

int check_color(int r, int g, int b)
{
    if (r < 0 || r > 255)
        return (0);
    if (g < 0 || g > 255)
        return (0);
    if (b < 0 || b > 255)
        return (0);
    return (1);
}