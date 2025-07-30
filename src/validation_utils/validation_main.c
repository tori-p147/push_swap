/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:33:14 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 18:57:43 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate(int argc, char **argv, t_array *unsorted_ints)
{
	t_nums	nums;
	int		n;

	if (argc <= 1)
		return (0);
	else if (argc > 2)
	{
		nums.nums = argv + 1;
		nums.allocated = false;
		if (!is_valid_nums(&nums, unsorted_ints))
			return (0);
	}
	else
	{
		nums.nums = parse_nums(&nums, argv[1]);
		if (!nums.nums)
			return (0);
		n = 0;
		while (nums.nums[n] != NULL)
			n++;
		if (n <= 1)
		{
			// ./push_swap "1 2 3 4 5" не должен возвращать ошибку если масив отсортирован
			free_nums(nums.nums);
			return (1);
		}
		if (!is_valid_nums(&nums, unsorted_ints))
			return (0);
	}
	return (1);
}
