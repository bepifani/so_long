/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:55:52 by bepifani          #+#    #+#             */
/*   Updated: 2022/02/10 17:40:29 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_sl    solong;

    if (argc == 2)
    {
        ft_make_map(&solong, argv[1]);
    }
    else
        write (1, "Error\n", 6);
}
