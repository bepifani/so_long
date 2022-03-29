/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:55:52 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/17 18:00:14 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_helper_coin(t_sl *sl)
{
	sl->steps++;
	ft_putnbr_fd(sl->steps, 0);
	write (1, "\n", 1);
}

void	ft_init(t_sl *sl)
{
	sl->map = NULL;
	sl->mlx = NULL;
	sl->win = NULL;
	sl->image = NULL;
	sl->win_game = 0;
	sl->lose = 0;
	sl->steps = 0;
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	ft_init(&sl);
	if (argc == 2)
		ft_make_map(&sl, argv[1]);
	else
	{
		write (1, "Error, wrong arguments\n", 23);
		return (0);
	}
	if (ft_check_map(&sl) == 0)
	{
		write (1, "Error, not valid map\n", 21);
		ft_end(&sl);
		return (0);
	}
	sl.length = (int)(ft_strlen(sl.map[1]));
	sl.mlx = mlx_init();
	sl.win = mlx_new_window(sl.mlx, (sl.length - 1) * 32,
			sl.hight * 32, "SO LONG");
	ft_fill_map(&sl);
	mlx_key_hook(sl.win, ft_key, &sl);
	mlx_hook(sl.win, 17, 0, ft_exit, NULL);
	mlx_loop(sl.mlx);
	return (0);
}
