/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:58 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/22 09:31:27 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	str = malloc((sizeof (char)) * i + 1);
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_line(char *line, char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = "";
	char		buff[BUFFERSIZE + 1];
	char		*line;
	ssize_t		cursor;

	cursor = 1;
	while ((cursor > 0))
	{
		cursor = read(fd, buff, BUFFERSIZE);
		buff[cursor] = '\0';
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n'))
		{
			line = malloc((sizeof (char)) * ft_linelen(stash) + 1);
			line = get_line(line, stash);
			stash = clear_stash(stash);
			return (line);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	close(fd);
	return (0);
}
