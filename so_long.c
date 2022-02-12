/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:55:52 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/12 19:21:38 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_init(t_sl *sl)
{
    sl->map = NULL;
	sl->mlx = NULL;
	sl->win = NULL;
}

// void	ft_set_hook(t_sl *sl)
// {
// 	mlx_hook(sl->win, 2, 1L << 0, ft_wasd, sl);
// 	ft_fill_map(sl);
// 	mlx_loop_hook(sl->mlx, ft_fill_map, sl);
// }

int main(int argc, char **argv)
{
    t_sl    solong;

    ft_init(&solong);
	solong.win_game = 0;
	solong.lose = 0;
    if (argc == 2)
    {
        ft_make_map(&solong, argv[1]);
    }
    else
        write (1, "Error\n", 6);
    int i = 0;
    size_t j = 0;
    while(i < solong.hight)
    {
        j = 0;
        while (j < ft_strlen(solong.map[i]))
        {
            printf("%c", solong.map[i][j]);
            j++;
        }
        i++;
    }
	printf("\n");
	printf("mony=%d, x=%d, y=%d\n", solong.mony, solong.x, solong.y);
	solong.length = (int)(ft_strlen(solong.map[1]));
	solong.mlx = mlx_init();
	solong.win = mlx_new_window(solong.mlx, (solong.length - 1) * 32, solong.hight * 32, "SO LONG");
	//ft_set_hook(&solong);
	// void *q;
	// mlx_hook(solong.win, 2, 1L << 0, q, solong);
	// ft_fill_map(&solong);
	mlx_key_hook(solong.win, ft_key, &solong);
	// //mlx_hook(solong.win, 17, 1L << 0, ft_end, &solong);
	//mlx_loop_hook(solong.mlx, ft_fill_map, &solong);
	ft_fill_map(&solong);
	mlx_loop(solong.mlx);
}
