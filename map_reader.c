/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:21:38 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 17:40:09 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_find_hight(char *argv)
{
    int     file;
    int     i;
    char    *line;

    i = 0;
    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "Error, wrong file\n", 18);
    while (1)
    {
        line = get_next_line(file);
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
    int     file;
    int     i;
    char    *line;

    i = 0;
    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "Error, wrong file\n", 18);
    line = get_next_line(file);
    while (line[i] != '\0')
        i++;
    close (file);
    return (i);
}

void    ft_find_positions(char *argv)
{
    int file;

    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "Error, wrong file\n", 18);
    close(file);
}

void    ft_make_map(t_sl *solong, char *argv)
{
    int file;
    int hight;
    int i;

    //if (ft_strlen(argv))
    //ft_check_map(argv); // проверка карты на валидность
    i = 0;
    file = open(argv, O_RDONLY);
    if (!file)
        write(1, "Error, wrong file\n", 18);
    solong->hight = ft_find_hight(argv);
    solong->length = ft_find_length(argv);
    hight = solong->hight;
    solong->map = malloc((solong->hight + 1) * sizeof(char *));
    if (!solong->map)
        free(solong->map);
    while (hight > 0)
    {
        solong->map[i] = get_next_line(file);
        hight--;
        i++;
    }
    close (file);
    ft_find_positions(argv);
}