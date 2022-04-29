/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:05:15 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 16:47:03 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_mlx
{
	int		fd;
	int		height;
	int		width;
	int		player_count;
	int		column_count;
	int		exit_count;
	int		player_x;
	int		player_y;
	int		count;
	int		collectible;

	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collect;
	void	*mlx_ptr;
	void	*win;
}		t_mlx;

int		diff_inputs(int keypress, t_mlx *mlx);
int		check_ber(char *s);
int		error_check(t_mlx *mlx);
void	add_graphics(t_mlx *mlx);
void	place_img(t_mlx *mlx);
int		read_map(t_mlx *mlx, char **s);
int		exit_game(t_mlx *mlx);

#endif
