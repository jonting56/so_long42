/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <jting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:57:19 by jting             #+#    #+#             */
/*   Updated: 2022/04/29 17:03:50 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	so_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_ber(char *map_name)
{
	int		i;
	int		j;
	char	*s;

	s = ".ber";
	j = 0;
	i = so_strlen(map_name) - 4;
	while (map_name[i])
	{
		if (map_name[i] != s[j])
			return (0);
		i++;
		j++;
	}	
	return (1);
}