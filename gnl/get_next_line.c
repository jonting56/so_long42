/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:20:53 by jting             #+#    #+#             */
/*   Updated: 2022/04/20 11:37:20 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_all(int fd, char *s_remain)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!gnl_strchr(s_remain, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 1)
			break ;
		buff[read_bytes] = '\0';
		s_remain = gnl_strjoin(s_remain, buff);
	}
	free(buff);
	if (s_remain)
		return (s_remain);
	return (0);
}

char	*ft_get_line(char *s_remain)
{
	int		i;
	char	*str;

	i = 0;
	if (!s_remain[i])
		return (NULL);
	while (s_remain[i] && s_remain[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s_remain[i] && s_remain[i] != '\n')
	{
		str[i] = s_remain[i];
		i++;
	}
	if (s_remain[i] == '\n')
	{
		str[i] = s_remain[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_remainder(char *s_remain)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s_remain[i] && s_remain[i] != '\n')
		i++;
	if (!s_remain[i])
	{
		free(s_remain);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(s_remain) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s_remain[i] != '\0')
		str[j++] = s_remain[i++];
	str[j] = '\0';
	free (s_remain);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s_remain;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s_remain = ft_read_all(fd, s_remain);
	if (!s_remain)
		return (NULL);
	line = ft_get_line(s_remain);
	s_remain = ft_remainder(s_remain);
	return (line);
}
