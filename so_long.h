/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:31:57 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 17:39:22 by bepifani         ###   ########.fr       */
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

typedef struct s_sl {
    char    **map;
    void    *mlx;
    int     hight;
    int     length;
    int     x;
    int     y;
    int     win;
    int     lose;
}   t_sl;

int     ft_find_hight(char *argv);
int     ft_find_length(char *argv);
void    ft_find_positions(char *argv);
void    ft_make_map(t_sl *solong, char *argv);

#endif