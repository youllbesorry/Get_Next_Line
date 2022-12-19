/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:58 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/19 18:17:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	size_t		size;
	char		*str;
	static char	buff[BUFFERSIZE];

	str = malloc((sizeof (char)));
	size = read(fd, buff, BUFFERSIZE);
	while (ft_strchr(buff, '\0', 0) < 0 && ft_strchr(buff, '\n', 0) < 0)
	{
		str = ft_strjoin(str, buff);
		str[size] = '\0';
		size += read(fd, buff, BUFFERSIZE);
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
	int		i;

	fd = open("test.txt", O_RDONLY);
	//next_line = get_next_line(fd);
	i = 0;
	while (i < 3)
	{
		next_line = get_next_line(fd);
		printf("Test =  %s\n", next_line);
		//free(next_line);
		i++;
	}
	free(next_line);
	close(fd);
	return (0);
}
/*int    main(void)
{
    int    fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
    }
    free(line);
    close(fd);
    return (0);
}*/