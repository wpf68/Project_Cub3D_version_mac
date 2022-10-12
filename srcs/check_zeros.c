/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:15:44 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/12 14:41:50 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\0')
        return (0);
    return (1);
}

int check_zeros(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (++i < game->map.lines - 1)
    {
        while (++j < (int)(ft_strlen(game->map.tab[i])- 1))
        {
            if (find_char(game->map.tab[i][j], "0NSEW"))
            {
                if (check_space(game->map.tab[i + 1][j]) == 0 
                    || check_space(game->map.tab[i + 1][j + 1]) == 0 
                    || check_space(game->map.tab[i + 1][j - 1]) == 0 
                    || check_space(game->map.tab[i][j + 1])== 0 
                    || check_space(game->map.tab[i][j - 1]) == 0 
                    || check_space(game->map.tab[i - 1][j]) == 0 
                    || check_space(game->map.tab[i - 1][j + 1]) == 0 
                    || check_space(game->map.tab[i - 1][j - 1]) == 0)
                        return (0);
            }
            
        }
        j = 0;
    }
    return (1);
}