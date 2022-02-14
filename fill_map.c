/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:17:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/14 19:51:27 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_to_map(t_sl *sl, int x, int y, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	sl->image = mlx_xpm_file_to_image(sl->mlx, name, &i, &j);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->image, x * 32, y * 32);
}

void	ft_helper_fill_map(t_sl *solong, int i, size_t j)
{
	while (j < ft_strlen(solong->map[i]))
		{
			if (solong->map[i][j] == '1')
				ft_image_to_map(solong, j, i, WATER);
			else
				ft_image_to_map(solong, j, i, GRASS);
			if (solong->map[i][j] == 'P')
				ft_image_to_map(solong, solong->y, solong->x, PIG);
			else if (solong->map[i][j] == 'W')
				ft_image_to_map(solong, j, i, WOLF);
			else if (solong->map[i][j] == 'C')
				ft_image_to_map(solong, j, i, DONAT);
			else if (solong->map[i][j] == 'E')
				ft_image_to_map(solong, j, i, EXIT1);
			j++;
		}
}
int	ft_fill_map(t_sl *solong)
{
	int		i;
	size_t	j;

	i = 0;
	mlx_clear_window(solong->mlx, solong->win);
	while (i < solong->hight)
	{
		j = 0;
		ft_helper_fill_map(solong, i, j);
		i++;
	}
	return (0);
}
