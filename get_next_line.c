/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:58 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/21 15:45:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_save(char *line, char *save)
{
	size_t	len_str;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	len_str = 0;
	while (save[i] != '\n')
		i++;
	len_str = ft_strlen(save) - ft_strlen(line);
	str = malloc((sizeof (char) * len_str + 1));
	if (!str)
		return (NULL);
	while (save[i + 1] != '\0')
	{
		str[j] = save[i + 1];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	clear_buff(char *buff, char *save)
{
	//size_t	len_str;
	size_t	i;
	size_t	j;
	//char	*str;

	i = 0;
	j = 0;
	//len_str = 0;
	while (buff[i] != '\n')
		i++;
	//len_str = ft_strlen(save) - ft_strlen(line);
	//str = malloc((sizeof (char) * len_str + 1));
	//if (!str)
	//	return (NULL);
	while (buff[i + 1] != '\0')
	{
		buff[j] = buff[i + 1];
		i++;
		j++;
	}
	buff[j] = '\0';
	//return (str);
}

char	*get_line(char *line, char *save)
{
	size_t	i;

	i = 0;
	while (save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFERSIZE + 1];
	static char		*save;
	char			*line;
	size_t			cursor;
	static int		already = 0;

	cursor = 1;
	if (!already)
	{
		save = malloc((sizeof (char)));
		already = 1;
	}
	while (cursor != 0 || cursor == -1)
	{
		cursor = read(fd, buff, BUFFERSIZE);
		save = ft_strjoin(save, buff);
		if (ft_strchr(save, '\n') == 1)
		{
			line = malloc((sizeof (char)) * ft_strlen(save));
			if (!line)
				return (NULL);
			line = get_line(line, save);
			save = clear_save(line, save);
			if (!save)
				return (NULL);
			return (line);
		}
	}
	return (NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;

// 	fd = open("test.txt", O_RDONLY);
// 	while (next_line)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			break ;
// 		printf("Test =  '%s'\n", next_line);
// 		free(next_line);
// 	}
// 	//free(next_line);
// 	close(fd);
// 	return (0);
// }
int    main(void)
{
    int    fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
	printf("%s", line);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
    free(line);
    close(fd);
    return (0);
}