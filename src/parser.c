/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:02:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 22:59:36 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_nums(t_nums *nums, char *arg)
{
	int	i;

	i = 0;
	nums->nums = ft_split(arg, ' ');
	if (!nums->nums)
	{
		free_and_return_error(nums, NULL);
		return (NULL);
	}
	nums->allocated = true;
	i = 0;
	while (nums->nums[i] != NULL)
		i++;
	if (i <= 1)
	{
		free_nums(nums);
		return (0);
	}
	return (nums->nums);
}
