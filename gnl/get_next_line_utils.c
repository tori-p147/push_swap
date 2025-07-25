/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:06:12 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/07 22:15:36 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *s)
{
	char	*new_line;
	int		len;
	int		i;

	len = gnl_strlen(s);
	new_line = (char *)malloc(len + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[len] = '\0';
	return (new_line);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	unsigned const char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = dest;
	psrc = src;
	while (n--)
		*(pdest++) = *(psrc++);
	return (dest);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	sum_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	sum_len = s1_len + s2_len;
	dest = malloc(sum_len + 1);
	if (!dest)
		return (NULL);
	gnl_memcpy(dest, s1, s1_len);
	gnl_memcpy(dest + s1_len, s2, s2_len + 1);
	return (dest);
}
