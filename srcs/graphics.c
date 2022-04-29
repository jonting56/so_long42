/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:12:55 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 15:56:21 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	place_player(t_mlx *mlx, int width, int height)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->player, width * 50, height * 50);
	mlx->player_y = height;
	mlx->player_x = width;
}

static	void	place_collect(t_mlx *mlx, int width, int height)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->collect, width * 50, height * 50);
	mlx->collectible++;
}

void	place_img(t_mlx *mlx)
{
	int	i;
	int	j;

	mlx->floor = mlx_xpm_file_to_image(mlx->mlx_ptr, "imgs/0.xpm", &i, &j);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "imgs/1.xpm", &i, &j);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "imgs/P.xpm", &i, &j);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "imgs/E.xpm", &i, &j);
	mlx->collect = mlx_xpm_file_to_image(mlx->mlx_ptr, "imgs/C.xpm", &i, &j);
}

void	add_graphics(t_mlx *mlx)
{
	int	height;
	int	width;

	mlx->collectible = 0;
	height = 0;
	while (height < mlx->height)
	{
		width = 0;
		while (mlx->map[height][width])
		{
			if (mlx->map[height][width] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->wall, (width * 50), (height * 50));
			if (mlx->map[height][width] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->floor, (width * 50), (height * 50));
			if (mlx->map[height][width] == 'P')
				place_player(mlx, width, height);
			if (mlx->map[height][width] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->exit, width * 50, height * 50);
			if (mlx->map[height][width] == 'C')
				place_collect(mlx, width, height);
			width++;
		}
		height++;
	}
}
