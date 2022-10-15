/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:06:58 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/07/27 09:17:57 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int count_char(char *str, char c)
{
    int x;
    int count;

    x = 0;
    count = 0;
    while (str[x] != '\0' && ft_isprint(str[x]) != 0)
    {
        if (str[x] == c)
            count++;
        x++;
    }
    return (count);
}