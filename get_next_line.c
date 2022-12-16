/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:58 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/16 16:31:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buff, int fd)
{
	char	*str;
	size_t	i;
	char	*line;
	ssize_t	size;

	i = 0;
	size = 1;
	str = NULL;
	str = malloc((sizeof (char)) * BUFFERSIZE + 1);
	if (!str)
		return (NULL);
	size = read(fd, buff, BUFFERSIZE);
	printf("size %ld", size);
	if (size == 0)
		return (NULL);
	/*while (i != size)
	{	
		str = ft_strjoin(str, buff);
		i++;
	}*/
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFERSIZE];

	if (fd == -1)
		return (NULL);
	return (get_line(buff, fd));
}

int    main(void)
{
    int		fd;
    char	*line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    while(line)
    {
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
    }
    free(line);
    close(fd);
    return (0);
}