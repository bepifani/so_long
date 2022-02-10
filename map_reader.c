/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:21:38 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 16:55:14 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_find_hight(char *argv)
{
    int     file;
    int     i;
    char    *line

    i = 0;
    file = open(argv, O_RDONLY);
    if (file < 0)
        write (1, "error\n", 6);
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

void    ft_make_map(t_solong *solong, char *argv)
{
    int file;
    int lenth;

    //if (ft_strlen(argv))
    file = open(argv, O_RDONLY);
    if (!file)
        write(1, "error\n", 6);
    solong->hight = ft_find_hight(argv);
    solong->lenth = ft_find_lenth(argv);
    lenth = solong->lenth;
    solong->map = malloc(solong->hight * solong->lenth * sizeof(char *));
    if (!solong->map)
        free(solong->map);
    while (lenth > 0)
    {
        solong->map[i] = get_next_line(file);
        lenth--;
    }
    close (file);
}