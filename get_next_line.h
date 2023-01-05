/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:55 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/05 16:37:25 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_strlen(char *str);
char	*ft_strnjoin(char *s1, char *s2, ssize_t n);
ssize_t	ft_strchr(char *s, int c);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

#endif