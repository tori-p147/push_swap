/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:17:34 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 21:48:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_arguments(t_nums *nums, char **argv, t_array *ints)
{
	nums->nums = parse_nums(nums, *argv);
	if (!nums->nums)
		return (0);
	nums->allocated = true;
	if (!is_valid_nums(nums, ints))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_nums	nums;
	t_llist	sorted_list;
	t_array	ints;

	if (argc <= 1)
	{
		ft_printf("wrong args\n");
		return (1);
	}
	else if (argc > 2)
	{
		nums.nums = argv + 1;
		nums.allocated = false;
		if (argc > 2 && !is_valid_nums(&nums, &ints))
			return (1);
		// for (int j = 0; j < ints.length; j++)
		// 	ft_printf("%d\n", ints.ints[j]);
		ints = sort(&ints);
		sorted_list = create_list(&sorted_list, &ints);
	}
	else
	{
		if (!parse_arguments(&nums, &argv[1], &ints))
			return (1);
		ints = sort(&ints);
		sorted_list = create_list(&sorted_list, &ints);
		return (0);
	}
	return (0);
}
