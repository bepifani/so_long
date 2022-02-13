/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:55:52 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/13 15:58:47 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_init(t_sl *sl)
{
    sl->map = NULL;
	sl->mlx = NULL;
	sl->win = NULL;
}

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
	if (ft_check_map(&solong) == 0)
	{
		write (1, "Error, not valid map\n", 21);
		return (0);
	}
	solong.length = (int)(ft_strlen(solong.map[1]));
	solong.mlx = mlx_init();
	solong.win = mlx_new_window(solong.mlx, (solong.length - 1) * 32, solong.hight * 32, "SO LONG");
	mlx_key_hook(solong.win, ft_key, &solong);
	ft_fill_map(&solong);
	mlx_loop(solong.mlx);
}
