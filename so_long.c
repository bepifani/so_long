/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:55:52 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 19:24:35 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_init(t_sl *sl)
{
    sl->map = NULL;
}

int main(int argc, char **argv)
{
    t_sl    solong;

    ft_init(&solong);
    if (argc == 2)
    {
        ft_make_map(&solong, argv[1]);
    }
    else
        write (1, "Error\n", 6);
    int i = 0;
    int j = 0;
    printf("%d\n", solong.hight);
    printf("%d\n", solong.length);
    while(i < solong.hight)
    {
        j = 0;
        while (j < solong.length)
        {
            printf("%c", solong.map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
