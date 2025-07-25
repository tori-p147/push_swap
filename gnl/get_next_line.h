/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:42:46 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/11 15:10:10 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *str, char c);
char	*gnl_strdup(char *s);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, size_t len);
char	*extract_line(char **stash);
char	*read_and_stash(int fd, char *stash, char *buffer);
char	*get_next_line(int fd);

#endif