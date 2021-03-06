/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:27:28 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/17 18:00:18 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_mony(t_sl *sl, int i, int j)
{
	sl->map[i][j] = '0';
	sl->find_mony++;
	ft_image_to_map(sl, sl->x * 32, sl->y * 32, GRASS);
}

void	ft_helper_player_move(t_sl *sl, int i, int j)
{
	if (sl->map[i + sl->x][j + sl->y] == '0')
	{
		sl->map[i + sl->x][j + sl->y] = 'P';
		sl->map[sl->x][sl->y] = '0';
	}
	sl->x = sl->x + i;
	sl->y = sl->y + j;
}

void	ft_player_move(t_sl *sl, int i, int j)
{
	if (sl->map[i + sl->x][j + sl->y] == '1')
	{
		ft_helper_coin2(sl);
		return ;
	}
	if (sl->map[i + sl->x][j + sl->y] == 'C')
		ft_get_mony(sl, sl->x + i, sl->y + j);
	else if (sl->map[i + sl->x][j + sl->y] == 'W')
	{
		sl->lose = 1;
		ft_end(sl);
	}
	else if (sl->map[i + sl->x][j + sl->y] == 'E')
	{
		if (sl->mony == sl->find_mony)
		{
			sl->win_game = 1;
			ft_end(sl);
		}
		else
			ft_helper_coin2(sl);
	}
	if (sl->map[i + sl->x][j + sl->y] != '1')
		ft_helper_coin(sl);
	ft_helper_player_move(sl, i, j);
}

int	ft_end(t_sl *sl)
{
	int	i;

	i = 0;
	if (sl->lose == 1)
		write(1, "============= Game over;( =============\n", 41);
	if (sl->win_game == 1)
		write(1, "============= You win! =============\n", 37);
	while (i < sl->hight)
	{
		free(sl->map[i]);
		sl->map[i] = NULL;
		i++;
	}
	exit (EXIT_SUCCESS);
}

int	ft_key(int key, t_sl *sl)
{
	if (sl->win_game == 1 || sl->lose == 1)
		ft_end(sl);
	if (key == A)
		ft_player_move(sl, 0, -1);
	if (key == D)
		ft_player_move(sl, 0, 1);
	if (key == W)
		ft_player_move(sl, -1, 0);
	if (key == S)
		ft_player_move(sl, 1, 0);
	if (key == ESCAPE)
		ft_end(sl);
	ft_fill_map(sl);
	return (0);
}
