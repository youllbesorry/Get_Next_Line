/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:52 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/19 18:15:33 by bfaure           ###   ########lyon.fr   */
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

char	*ft_strncat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && src[j - 1] != '\n')
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
	ft_strncat(str, s1);
	return (free(s1), ft_strncat(str, s2));
}

ssize_t	ft_strchr(char *s, int c, size_t i)
{
	size_t	len;

	len = ft_strlen(s);
	while (len + 1)
	{
		if (s[i] == c)
			return (len - i);
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