/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:39:53 by jting             #+#    #+#             */
/*   Updated: 2022/04/20 11:37:28 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	dst = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			dst[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			dst[i++] = s2[j++];
	dst[i] = '\0';
	if (s1)
		free(s1);
	return (dst);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}
