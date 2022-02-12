/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:31:57 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/12 19:32:03 by bepifani         ###   ########.fr       */
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

# define ESCAPE 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_sl {
    char    **map;
    void    *mlx;
    int     hight;
    int     length;
    int     x;
    int     y;
    void     *win;
    int     lose;
	int		win_game;
    int     mony;
    int     steps;
    int     find_mony;
}   t_sl;


char	*ft_anim_player(t_sl *sl);

int     ft_find_hight(char *argv);
void    ft_make_map(t_sl *solong, char *argv);
void    ft_find_positions(t_sl  *solong);

void	ft_image_to_map(t_sl *solong, int x, int y, char *name);
int		ft_fill_map(t_sl *solong);

int		ft_key(int key, t_sl *sl);
void	ft_get_mony(t_sl *sl, int i, int j);
void	ft_player_move(t_sl *sl, int i, int j);
int		ft_end(t_sl *sl);

#endif