/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:14 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 15:43:11 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	find_width(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static int	add_line(t_mlx *mlx, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	mlx->height++;
	temp = (char **)malloc(sizeof(char *) * (mlx->height + 1));
	temp[mlx->height] = NULL;
	while (i < (mlx->height - 1))
	{
		temp[i] = mlx->map[i];
		i++;
	}
	temp[i] = line;
	if (mlx->map)
		free(mlx->map);
	mlx->map = temp;
	return (1);
}

int	read_map(t_mlx *mlx, char **s)
{
	char	*map;

	mlx->fd = open(s[1], O_RDONLY);
	if (mlx->fd < 0)
		return (0);
	while (1)
	{
		map = get_next_line(mlx->fd);
		if (!add_line(mlx, map))
			break ;
	}
	close (mlx->fd);
	mlx->width = find_width(mlx->map[0]);
	return (1);
}