/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:52 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/09 12:53:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, ssize_t n)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (free(s1), NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (clear_buff(s2), free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	k = 0;
	while (s2[k] && k <= n)
		str[i++] = s2[k++];
	return (str[i] = '\0', free(s1), str);
}

ssize_t	ft_strchr(char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (count != 0 && SIZE_MAX / count < size)
		return (NULL);
	len = size * count;
	ptr = malloc (len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (len--)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *) ptr);
}
