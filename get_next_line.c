/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:58 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/18 12:09:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	ssize_t		size;
	char		*str;
	static char	buff[BUFFERSIZE];
	size_t		i;

	str = NULL;
	size = 1;
	str = malloc((sizeof (char)) * BUFFERSIZE + 1);
	size = read(fd, str, BUFFERSIZE);
	i = ft_strchr(str, '\n');
	while (i == 0)
	{
		str = ft_strjoin(str, buff);
		size = i - read(fd, buff, BUFFERSIZE);
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = get_line(fd);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("test.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s\n", next_line);
	free(next_line);
	close(fd);
	return (0);
}