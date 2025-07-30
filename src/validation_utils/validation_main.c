/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:33:14 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 22:59:49 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate(int argc, char **argv, t_array *unsorted_ints)
{
	t_nums	nums;

	nums.nums = NULL;
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
		if (!is_valid_nums(&nums, unsorted_ints))
			return (0);
	}
	return (1);
}
