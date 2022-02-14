/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:21:38 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/14 17:30:47 by bepifani         ###   ########.fr       */
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
	{
        write (1, "Error, wrong file\n", 18);
		exit(0);
	}
    line = get_next_line(file);
	free (line);
	while (line)
    {
        line = get_next_line(file);
		free (line);
        i++;
    }
	free(line);
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

int	ft_check_p_e(t_sl *sl)
{
	int p = 0;
	int e = 0;
	int i =0;
	size_t j;
	int c= 0;

	while(i < sl->hight)
	{
		j = 0;
		while (j < ft_strlen(sl->map[i]))
		{
			if (sl->map[i][j] == 'P')
				p++;
			if (sl->map[i][j] == 'E')
				e++;
			if (sl->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c == 0)
		return (0);
	return (1);
}

int ft_check_walls(t_sl * sl)
{
	int i = 0;
	size_t j = 0;

	while (j < ft_strlen(sl->map[i]) - 1)
	{
		if (sl->map[i][j] != '1')
			return (0);
		j++;
	}
	i = sl->hight - 1;
	j = 0;
	while (j < ft_strlen(sl->map[i]))
	{
		if (sl->map[i][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	i = 0;
	while (i < sl->hight - 1)
	{
		if (sl->map[i][j] != '1')
			return (0);
		i++;
	}
	i = 0;
	j = ft_strlen(sl->map[i]) - 2;
	while (i < sl->hight - 1)
	{
		if (sl->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map(t_sl *sl)
{
	int i = 0;
	size_t j;

	while(i < sl->hight)
	{
		j = 0;
		while (j < ft_strlen(sl->map[i]))
		{
			if (sl->map[i][j] != 'P' && sl->map[i][j] != '0' && sl->map[i][j] != '1' && sl->map[i][j] != 'W'
				&& sl->map[i][j] != 'C' && sl->map[i][j] != 'E' && sl->map[i][j] != '\n')
				return (0);
			if (ft_strlen(sl->map[sl->hight - 1]) + 1 != ft_strlen(sl->map[0]))
			 	return (0);
			if (ft_strlen(sl->map[0]) != ft_strlen(sl->map[i]) && i != sl->hight - 1)
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check_p_e(sl) == 0 || ft_check_walls(sl) == 0)
		return (0);
	return (1);
}

void    ft_make_map(t_sl *solong, char *argv)
{
    int file;
    int i;

    i = 0;
    solong->hight = ft_find_hight(argv);
    solong->map = malloc((solong->hight + 1) * sizeof(char *));
    if (!solong->map)
        free(solong->map);
    solong->map[solong->hight] = NULL;
    file = open(argv, O_RDONLY);
    if (!file)
	{
        write(1, "Error, wrong file\n", 18);
		exit(0);
	}
    while (i < solong->hight)
    {
        solong->map[i] = get_next_line(file);
        i++;
    }
    close (file);
	
    ft_find_positions(solong);
}