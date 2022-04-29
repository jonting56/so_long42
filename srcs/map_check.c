/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:53:04 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 16:44:01 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	vert_check(t_mlx *mlx)
{
	int	height;
	int	width;

	height = 0;
	width = (mlx->width) - 1;
	while (height <= mlx->height)
    {
        if (mlx->map[height][width] != '1' && mlx->map[height][0] != '1')
            return (0);
        height++;
    }
    return (1);
}

int hor_check(t_mlx *mlx)
{
    int height;
    int width;

    height = mlx->height;
    width = (mlx->width) - 1;
    while (width >= 0)
    {
        if (mlx->map[height][0] != '1' && mlx->map[height][width] != '1')
            return (0);
        width--;
    }
    return (1);
}

int check_var(t_mlx *mlx)
{
    int count;
    int x;
    int y;

    x = 0;
    y = 0;
    count = 0;
    while (y <= mlx->height)
    {
        while (x <= mlx->width)
        {
            if (mlx->map[y][x] == 'C' || mlx->map[y][x] == 'E')
                count++;
            x++;    
        }
        x = 0;
        y++;
    }
    if (count == 2)
        return (1);
    return (0);
}

int error_check(t_mlx *mlx)
{
    if (!vert_check(mlx))
        return (0);
    if (!hor_check(mlx))
        return(0);
    if (!check_var(mlx))
       return (0);
    return (1);
}
