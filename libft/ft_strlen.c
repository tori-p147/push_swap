/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:15:10 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/29 13:46:56 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

// int	main(void)
// {
// 	printf("%zu", ft_strlen("abcd"));
// 	return (0);
// }
