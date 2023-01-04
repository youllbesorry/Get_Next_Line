/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:58 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/04 15:51:28 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_buff(char *buff)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strchr(buff, '\n') + 1;
	while (buff[i] && buff[i + len])
	{
		buff[i] = buff[i + len];
		i++;
	}
	buff[i] = '\0';
}

char	*line_get(char *buff, ssize_t cursor, char *line, int fd)
{
	while (cursor)
	{
		if (buff[0] == 0)
		{
			cursor = read(fd, buff, BUFFERSIZE);
			if (cursor == -1)
				return (free(line), NULL);
			buff[cursor] = '\0';
		}
		if (ft_strchr(buff, '\n') == -1 && ft_strchr(line, '\n') == -1
			&& cursor != 0)
		{
			line = ft_strnjoin(line, buff, BUFFERSIZE);
			if (!line)
				return (free(line), NULL);
			buff[0] = '\0';
			continue ;
		}
		line = ft_strnjoin(line, buff, ft_strchr(buff, '\n'));
		if (!line)
			return (free(line), NULL);
		clear_buff(buff);
		return (line);
	}
	return (free(line), NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFERSIZE + 1];
	ssize_t		cursor;
	char		*line;

	cursor = 1;
	if (fd < 0 || read(fd, 0, 0) > 0 || BUFFERSIZE < 1)
		return (buff[0] = 0, NULL);
	line = malloc((sizeof (char)));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = line_get(buff, cursor, line, fd);
	if (!line)
		return (NULL);
	if (line[0] == 0)
		return (NULL);
	else
		return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("bible.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
