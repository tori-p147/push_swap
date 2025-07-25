/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:51:40 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 20:09:16 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putunsint_fd(unsigned int n, int fd)
{
	char	c;
	ssize_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsint_fd(n / 10, fd);
	c = n % 10 + '0';
	count += write(fd, &c, 1);
	return (count);
}

ssize_t	convert_ulong_to_hex_value(unsigned long p, char c)
{
	const char	hex[16] = "0123456789abcdef";
	char		buffer[19];
	int			i;

	i = 19;
	if (p == 0)
		return (write(1, "(nil)", 5));
	while (p)
	{
		if (!ft_isdigit(hex[p % 16]) && c == 'X')
			buffer[--i] = ft_toupper((int)hex[p % 16]);
		else
			buffer[--i] = hex[p % 16];
		p /= 16;
	}
	if (c == 'p')
	{
		buffer[--i] = 'x';
		buffer[--i] = '0';
	}
	return (write(1, &buffer[i], 19 - i));
}

ssize_t	convert_uint_to_hex_value(unsigned int p, char c)
{
	const char	hex[16] = "0123456789abcdef";
	char		buffer[9];
	int			i;

	i = 9;
	if (p == 0)
		return (write(1, "0", 1));
	while (p)
	{
		if (!ft_isdigit(hex[p % 16]) && c == 'X')
			buffer[--i] = ft_toupper((int)hex[p % 16]);
		else
			buffer[--i] = hex[p % 16];
		p /= 16;
	}
	return (write(1, &buffer[i], 9 - i));
}
