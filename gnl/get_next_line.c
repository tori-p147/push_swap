/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:43:01 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/07 22:23:06 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_substr(char *s, size_t len)
{
	size_t	src_size;
	char	*substr;

	if (!s)
		return (NULL);
	src_size = gnl_strlen(s);
	if (src_size < len)
		len = src_size;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	gnl_memcpy(substr, s, len);
	substr[len] = '\0';
	return (substr);
}

/// Read from buffer and joining stash
/// ssize_t bytes_read How many bytes was read while don`t found \n
/// char *stash The current buffer (may be NULL) to append read data to
/// char *tmp Used to store old stash for freeing after join
/// @return All buffer if stash blank || if stash exists append buff
char	*read_and_stash(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (!gnl_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = stash;
		if (!stash)
			stash = gnl_strjoin("", buffer);
		else
			stash = gnl_strjoin(stash, buffer);
		free(tmp);
	}
	return (stash);
}

/// Line extractor
/// @param stash pointer to stash for can to return updated stash
/// char *pn Pointer \n symbol (for check end of line & update stash by rest)
/// char *line Extracted line
/// char *rest Remaining stash after the extracted line
/// int len Length of line -> if found \n length =
///  diff of pointer to \n and start of *stash -> else length = all stash
/// @return Extracted line
char	*extract_line(char **stash)
{
	char	*pn;
	char	*line;
	char	*rest;
	size_t	len;

	pn = gnl_strchr(*stash, '\n');
	if (pn)
		len = pn - *stash + 1;
	else
		len = gnl_strlen(*stash);
	line = gnl_substr(*stash, len);
	if (pn && *(pn + 1))
		rest = gnl_strdup(pn + 1);
	else
		rest = NULL;
	free(*stash);
	*stash = rest;
	return (line);
}

/// Main function for read buffer and shash or extract new line
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __SIZE_MAX__)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_and_stash(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("text1.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }