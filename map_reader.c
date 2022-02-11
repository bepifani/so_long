/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:21:38 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/11 16:23:20 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_find_hight(char *argv)
{
    int  file;
    int  i;
    char    *line;

    i = 0;
    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "Error, wrong file\n", 18);
    line = get_next_line(file);
    while (line)
    {
        line = get_next_line(file);
        i++;
    }
    close (file);
    return (i);
}

void    ft_find_positions(t_sl  *solong)
{
    int i;
    size_t j;

    i = 0;
    j = 0;
    solong->mony = 0;
    while(i < solong->hight)
    {
        j = 0;
        while (j < ft_strlen(solong->map[i]))
        {
            if (solong->map[i][j] == 'P')
            {
                solong->x = i;
                solong->y = j;
            }
            else if (solong->map[i][j] == 'C')
              solong->mony++;  
            j++;
        }
        i++;
    }
}

void    ft_make_map(t_sl *solong, char *argv)
{
    int file;
    int i;

    //if (ft_strlen(argv))
    //ft_check_map(argv); // проверка карты на валидность
    i = 0;
    solong->hight = ft_find_hight(argv);
    solong->map = malloc((solong->hight + 1) * sizeof(char *));
    if (!solong->map)
        free(solong->map);
    solong->map[solong->hight] = NULL;
    file = open(argv, O_RDONLY);
    if (!file)
        write(1, "Error, wrong file\n", 18);
    while (i < solong->hight)
    {
        solong->map[i] = get_next_line(file);
        i++;
    }
    close (file);
    ft_find_positions(solong);
}