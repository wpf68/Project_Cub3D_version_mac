/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:26 by mfuhrman          #+#    #+#             */
/*   Updated: 2022/10/15 10:04:56 by mfuhrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void parse_data_and_map(t_game *game, t_game *cube, char *argv)
{
    int     map_fd;
    int     i;
    char    *read_str;
    char    *temp;
    char    *temp2;

    i = 0;
    read_str = ft_strjoin("maps/", argv);
    init_parse(game);
    map_fd = open(read_str, O_RDONLY);
    free(read_str);
    if (map_fd == -1)
        error_msg("Error:\nLa map n' a pas pu s'ouvir !");
    read_str = get_next_line(map_fd);
    temp = ft_strdup("");
    while (read_str)
    {
       // printf("%s\n", read_str);
        if (game->parse.read_map == 0)
            parse_text_and_color(read_str, cube, game);
        else if (game->parse.read_map == 1)
        {
            if (empty_line(read_str))
                error_msg("Error:\nla map contient une ligne vide !");
            temp2 = temp;
            temp = ft_strjoin(temp2, read_str);
            free (temp2);
            i++;            
        }     
        read_str = get_next_line(map_fd);
    }
    close (map_fd);
    game->map.tab = ft_split(temp, '\n');
    game->map.lines = i;
    i = 0;
    while (i < game->map.lines)
	{
		if (game->map.columns < (int)ft_strlen(game->map.tab[i]))
				game->map.columns = ft_strlen(game->map.tab[i]);
		printf(" i = %d\n", i);
		i++;
	}
		write(1, "******\n", 7);

	i = 0;
	while (game->map.tab[i])
	{
		printf(" i = %d   lines = %d\n", i, game->map.lines);
		printf("%s\n", game->map.tab[i]);
		i++;

	}
		write(1, "******\n", 7);

    printf("texture Nord = %s\n", cube->name_text[0]); 
    printf("%zu\n", ft_strlen(cube->name_text[0])) ;
    printf("texture SUD = %s\n", cube->name_text[1]); 
    printf("%zu\n", ft_strlen(cube->name_text[1])) ;
    printf("texture OUEST = %s\n", cube->name_text[2]); 
    printf("%zu\n", ft_strlen(cube->name_text[2])) ;
    printf("texture WEST = %s\n", cube->name_text[3]); 
    printf("%zu\n", ft_strlen(cube->name_text[3])) ;
}

