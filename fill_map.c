/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:17:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/12 19:22:53 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_to_map(t_sl *solong, int x, int y, char *name)
{
	int	i = 0;
	int	j = 0;
	void	*image;

	image = mlx_xpm_file_to_image(solong->mlx, name, &i, &j);
	mlx_put_image_to_window(solong->mlx, solong->win, image, x * 32, y * 32);
}

int	ft_fill_map(t_sl *solong)
{
	int i;
	size_t j;

	i = 0;
	while (i < solong->hight)
	{
		j = 0;
		while(j < ft_strlen(solong->map[i]))
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
		i++;
	}
	return (0);
}