/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:09:43 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/27 22:13:18 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(const char *str, bool *error)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			result = ((result * 10) + (*str - '0'));
		else
		{
			*error = true;
			return (0);
		}
		str++;
	}
	result = result * sign;
	return (result);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("-2147483647"));
// 	printf("%d\n", ft_atoi("a7"));
// 	printf("%d\n", ft_atoi("\t\n\v\f\r--1")); // 0
// 	printf("%d\n", ft_atoi("\t\n\v\f\r++1")); // 0
// 	return (0);
// }