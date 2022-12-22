/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:55 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/22 08:26:17 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFERSIZE
#  define BUFFERSIZE 10
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_strchr(char *s, int c);
char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_linelen(char *str);

#endif