/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:04:31 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/11 10:24:01 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_first_line(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.lines)
    {
        if (game->map.tab[i][0] == '1' || game->map.tab[i][0] == ' ')
            i++;
        else if (find_char(game->map.tab[i][0], "0NSEW"))
            return (0);
    }
    return (1);
}

int check_last_line(t_game *game)
{
    int i;
    int end;

    i = 0;
    end = game->map.columns - 1;
    while (i < game->map.lines)
    {
        if (game->map.tab[i][end] == '1' || game->map.tab[i][end] == ' ')
            i++;
        else if (find_char(game->map.tab[i][end], "0NSEW"))
            return (0);    
    }
    return (1);
}

int check_first_column(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.columns)
    {
        if (game->map.tab[0][i] == '1' || game->map.tab[0][i] == ' ')
            i++;
        else if (find_char(game->map.tab[0][i], "0NSEW"))
            return (0);    
    }
    return (1);
}

int check_last_column(t_game *game)
{
    int i;
    int end;

    i = 0;
    end = game->map.lines - 1;
    while (i < game->map.columns)
    {
        if (game->map.tab[end][i] == '1' || game->map.tab[end][i] == ' ')
            i++;
        else if (find_char(game->map.tab[end][i], "0NSEW"))
            return (0);
    }
    return (1);
}

int check_border_map(t_game *game)
{
    if (check_first_line(game) == 0)
        return (0);
    if (check_last_line(game) == 0)
        return (0);
    if (check_first_column(game) == 0)
        return (0);
    if (check_last_column(game) == 0)
        return (0);
    else
        return (1);    
}