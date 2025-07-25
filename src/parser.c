/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:02:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/25 18:17:47 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_nums(char *arg)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(arg, ' ');
	if (!nums)
	{
		error();
		return (NULL);
	}
	return (nums);
}
