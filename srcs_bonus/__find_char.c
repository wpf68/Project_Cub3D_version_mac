/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:38 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/10 13:22:18 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int find_char(char p, char *caracters)
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