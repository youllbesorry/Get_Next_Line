/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:52 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/18 12:05:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	ft_strcat(str, s1);
	return (ft_strcat(str, s2));
}

size_t	ft_strchr(char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (len + 1)
	{
		if (s[i] == c)
			return (i - len + 1);
		i++;
		len--;
	}
	return (-1);
}

// int	main(void)
// {
// 	char	str[] = "premiere ligne\n";

// 	printf("%ld \n", ft_strchr(str, '\n'));
// 	return (0);
// }