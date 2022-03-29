/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:52:12 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/17 17:59:46 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_helper_check_map(t_sl *sl)
{
	if (ft_check_p_e(sl) == 0 || ft_check_walls(sl) == 0)
		return (0);
	return (1);
}

int	ft_helper_check_walls(t_sl *sl, int i, size_t j)
{
	i = 0;
	j = 0;
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
	return (1);
}

int	ft_find_hight(char *argv)
{
	int		file;
	int		i;
	char	*line;

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

int	ft_exit(void)
{
	exit (0);
	return (0);
}

void	ft_helper_coin2(t_sl *sl)
{
	ft_putnbr_fd(sl->steps, 0);
	write (1, "\n", 1);
}
