/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:31:57 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 16:38:14 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_solong {
    char    **map;
    void    *mlx;
    int     hight;
    int     lenth;
    int     x;
    int     y;
    int     win;
    int     lose;
}   t_solong;

#endif