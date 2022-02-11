/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:31:57 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/11 18:37:21 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <fcntl.h>

# define WATER "./image/WATER.xpm"
# define GRASS "./image/GRASS.xpm"
# define PIG "./image/PIG.xpm"
# define WOLF "./image/WOLF.xpm"
# define DONAT "./image/DONAT.xpm"
# define EXIT1 "./image/EXIT1.xpm"
# define EXIT2 "./image/EXIT2.xpm"

typedef struct s_sl {
    char    **map;
    void    *mlx;
    int     hight;
    int     length;
    int     x;
    int     y;
    void     *win;
    int     lose;
    int     mony;
    int     steps;
    int     find_mony;
}   t_sl;

int     ft_find_hight(char *argv);
void    ft_make_map(t_sl *solong, char *argv);
void    ft_find_positions(t_sl  *solong);

void	ft_image_to_map(t_sl *solong, int x, int y, char *name);
void	ft_fill_map(t_sl *solong);

#endif