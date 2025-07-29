/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:17:34 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/29 19:36:26 by vmatsuda         ###   ########.fr       */
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
	t_llist	*list_a;
	t_array	unsorted_ints;

	if (argc <= 1)
	{
		ft_printf("wrong args\n");
		return (1);
	}
	else if (argc > 2)
	{
		nums.nums = argv + 1;
		nums.allocated = false;
		if (argc > 2 && !is_valid_nums(&nums, &unsorted_ints))
			return (1);
	}
	else if (!parse_arguments(&nums, &argv[1], &unsorted_ints))
		return (1);
	list_a = NULL;
	list_a = create_list(list_a, &unsorted_ints);
	if (!list_a)
		return (1);
	return (0);
}
