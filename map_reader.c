/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:21:38 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 19:22:07 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_find_hight(char *argv, t_sl  *solong)
{
    int  file;
    int  i;
    char    *line;

    i = 0;
    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "Error, wrong file\n", 18);
        line = get_next_line(file);
        if (line )
        {
            solong->length  = ft_strlen(line);
            i++;
        }
        else 
            return 0;
    while (1)
    {
        line = get_next_line(file);
        // solong->length = ft_strlen(line);
        if (line)
            i++;
        else
            break ;
    }
    close (file);
    return (i);
}

int ft_find_length(char *argv)
{
    int  file;
    int  i;
    char    *line;

    i = 0;
    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "Error, wrong file\n", 18);
    line = get_next_line(file);
    while (line[i] != '\0')
        i++;
    close (file);
    return (i - 1);
}

void    ft_find_positions(t_sl  *solong)
{
    int i;
    int j;

    i = 0;
    j = 0;
    solong->mony = 0;
    while(i < solong->hight)
    {
        j = 0;
        while (j < solong->length)
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
    int hight;
    int i;

    //if (ft_strlen(argv))
    //ft_check_map(argv); // проверка карты на валидность
    i = 0;
    solong->hight = ft_find_hight(argv, solong);
    // solong->length = ft_find_length(argv);
    hight = solong->hight;
    solong->map = malloc((solong->hight + 1) * sizeof(char *));
    if (!solong->map)
        free(solong->map);
    solong->map[solong->hight] = NULL;
    file = open(argv, O_RDONLY);
    if (!file)
        write(1, "Error, wrong file\n", 18);
    // write(1, "\n", 1);
    while (hight > 0)
    {
        solong->map[i] = get_next_line(file);
        // write(1, solong->map[i], ft_strlen(solong->map[i]));
        // write(1, "\n", 1);
        hight--;
        i++;
    }
    close (file);
    ft_find_positions(solong);
}