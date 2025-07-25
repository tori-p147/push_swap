/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:06:20 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 20:09:53 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

ssize_t	ft_putunsint_fd(unsigned int n, int fd);
ssize_t	convert_ulong_to_hex_value(unsigned long p, char c);
ssize_t	convert_uint_to_hex_value(unsigned int p, char c);
ssize_t	check_format_and_print(const char *format, va_list argptr);
int		ft_printf(const char *format, ...);

#endif