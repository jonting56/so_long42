/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:52:29 by jting             #+#    #+#             */
/*   Updated: 2022/04/20 11:36:59 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, int c);
char	*ft_read_line(int fd, char *s_remain);
char	*ft_get_line(char *s_remain);
char	*ft_remainder(char *s_remain);
char	*get_next_line(int fd);
char	*gnl_strdup(char *s);

#endif
