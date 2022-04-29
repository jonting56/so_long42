/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:51:26 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 16:47:19 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_mem(void *p, int c, int len)
{
	unsigned char	*s;

	s = (unsigned char *)p;
	while (len--)
		*s++ = (unsigned char)c;
	return (p);
}

int	exit_game(t_mlx *mlx)
{
	int	line;

	line = 0;
	if (mlx->win)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	free (mlx->mlx_ptr);
	while (line < mlx->height - 1)
		free(mlx->map[line++]);
	free(mlx->map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2 || check_ber(av[1]))
	{	
		ft_printf("Please select a map file");
		return (0);
	}
	ft_mem(&mlx, 0, sizeof(t_mlx));
	error_check(&mlx);
	read_map(&mlx, av);
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, (mlx.width * 50), (mlx.height * 50), "So Long");
	place_img(&mlx);
	add_graphics(&mlx);
	mlx_key_hook(mlx.win, diff_inputs, &mlx);
	mlx_hook(mlx.win, 17, 0, (void *)exit, 0);
	mlx_loop(mlx.mlx_ptr);
}