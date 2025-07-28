/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:02:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 16:29:38 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_nums(t_nums *nums, char *arg)
{
	int	i;

	i = 0;
	nums->nums = ft_split(arg, ' ');
	if (!nums)
	{
		return_error("args format\n", nums, NULL);
		return (NULL);
	}
	nums->allocated = true;
	i = 0;
	while (nums->nums[i] != NULL)
		// printf("nums[%d] = %s\n", i, nums[i]);
		i++;
	if (i <= 1)
	{
		return_error("write more numbers\n", nums, NULL);
		return (NULL);
	}
	return (nums->nums);
}
