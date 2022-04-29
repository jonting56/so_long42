/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:20:10 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 15:55:30 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	valid_move(t_mlx *mlx, int x, int y)
{
	if (mlx->map[y][x] == 'E')
	{
		if (mlx->collectible != 0)
			return (0);
		ft_printf("Congratulations!\n");
		exit_game(mlx);
	}
	if (mlx->map[y][x] == '0')
	{
		mlx->map[y][x] = 'P';
		mlx->player_y = y;
		mlx->player_x = x;
		mlx->count++;
	}
	if (mlx->map[y][x] == 'C')
	{
		mlx->map[y][x] = 'P';
		mlx->player_y = y;
		mlx->player_x = x;
		mlx->collectible--;
		mlx->count++;
	}
	return (1);
}

static	int	up_down(int keypress, t_mlx *mlx)
{
	int	x;
	int	y;
	int	k;

	y = mlx->player_y;
	x = mlx->player_x;
	if (keypress == 13)
	{
		y--;
		if (mlx->map[y][x] == '1')
			return (0);
		k = valid_move(mlx, x, y);
		if (!k)
			return (0);
		mlx->map[y + 1][x] = '0';
	}
	if (keypress == 1)
	{
		y++;
		if (mlx->map[y][x] == '1')
			return (0);
		k = valid_move(mlx, x, y);
		if (!k)
			return (0);
		mlx->map[y - 1][x] = '0';
	}
	ft_printf("Moves made : %d\n", mlx->count);
	return (1);
}

static	int	left_right(int keypress, t_mlx *mlx)
{
	int	x;
	int	y;
	int	k;

	y = mlx->player_y;
	x = mlx->player_x;
	if (keypress == 0)
	{
		x--;
		if (mlx->map[y][x] == '1')
			return (0);
		k = valid_move(mlx, x, y);
		if (!k)
			return (0);
		mlx->map[y][x + 1] = '0';
	}
	if (keypress == 2)
	{
		x++;
		if (mlx->map[y][x] == '1')
			return (0);
		k = valid_move(mlx, x, y);
		if (!k)
			return (0);
		mlx->map[y][x - 1] = '0';
	}
	ft_printf("Moves made : %d\n", mlx->count);
	return (1);
}

int	diff_inputs(int keypress, t_mlx *mlx)
{
	int	valid;

	valid = 0;
	if (keypress == 13 || keypress == 1)
		valid = up_down(keypress, mlx);
	if (keypress == 0 || keypress == 2)
		valid = left_right(keypress, mlx);
	if (keypress == 53)
		valid = exit_game(mlx);
	if (valid)
		add_graphics(mlx);
	return (valid);
}