/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:24:52 by bfaure            #+#    #+#             */
/*   Updated: 2022/12/22 17:08:53 by bfaure           ###   ########lyon.fr   */
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

char	*ft_strnjoin(char *s1, char *s2, ssize_t n)
{
	char	*str;
	size_t	len;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc (sizeof(char) * (ft_strlen(s1) + n + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	k = 0;
	while (s2[k] && k < n)
		str[i++] = s2[k++];
	return (str[i] = '\0', free(s1), str);
}

ssize_t	ft_strchr(char *s, int c)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}
