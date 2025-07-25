/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:04:26 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/15 20:09:29 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	check_format_and_print(const char *format, va_list argptr)
{
	if (*format == 'c')
		return (ft_putchar_fd(va_arg(argptr, int), 1));
	else if (*format == 's')
		return (ft_putstr_fd(va_arg(argptr, char *), 1));
	else if (*format == 'p')
		return (convert_ulong_to_hex_value(va_arg(argptr, unsigned long),
				*format));
	else if (*format == 'i' || *format == 'd')
		return (ft_putnbr_fd(va_arg(argptr, int), 1));
	else if (*format == 'u')
		return (ft_putunsint_fd(va_arg(argptr, unsigned int), 1));
	else if (*format == 'x' || *format == 'X')
		return (convert_uint_to_hex_value(va_arg(argptr, unsigned int),
				*format));
	else if (*format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	ssize_t	count;
	va_list	argptr;

	count = 0;
	if (!format)
		return (-1);
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += check_format_and_print(format, argptr);
		}
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(argptr);
	return ((int)count);
}

// int	main(void)
// {
// 	// char *p;

// 	// p = NULL;
// 	// ft_printf(" %p ", (void *)-1);
// 	// printf(" %p ", (void *)-1);
// 	int rtn1 = ft_printf(" %u ", INT_MAX);
// 	// int rtn2 = printf(" %u ", INT_MAX);
// 	printf(" %d", rtn1);
// 	// printf(" %d", rtn2);
// 	// printf(" %p %p ", (void *)0, (void *)0);
// 	// ft_printf(" %p %p ", (void *)0, (void *)0);
// 	// ft_printf("%i", i);
// 	// ft_printf(" %d %d", LONG_MAX, LONG_MIN);
// 	// printf("\n");
// 	// printf(" %ld %ld", LONG_MAX, LONG_MIN);
// 	// printf("\n");
// 	// printf(" %u ", 10);
// 	// ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
// 	// 	ULONG_MAX, 0, -42);
// 	// printf("\n");
// 	// printf(" %d %d %ld %ld %ld %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
// 	// 	ULONG_MAX, 0, -42);
// 	// ft_printf(" %X %X %X %X %X", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// printf("\n");
// 	// printf(" %lX %lX %lX %X %X", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// printf(" %x ", 0);
// 	// ft_printf(" %x ", 0);
// 	return (0);
// }