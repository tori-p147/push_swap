/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:17:34 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 19:00:10 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*parse_arguments(t_nums *nums, char **argv)
{
	t_array ints;

	nums->nums = parse_nums(&nums, argv[1]);
	if (!nums->nums)
		return (NULL);
	nums->allocated = true;
	if (!is_valid_nums(&nums))
		return (NULL);

	return (1);
}

int	main(int argc, char **argv)
{
	t_nums	nums;
	t_llist	sorted_list;
	t_array *ints;

	if (argc == 1)
	{
		ft_printf("wrong args\n");
		return (1);
	}
	if (argc == 2)
	{
		if (!parse_arguments(&nums, argv[1]))
			return (1);
		sorted_list = sort(&nums);
		return (0);
	}
	nums.nums = argv + 1;
	nums.allocated = false;
	if (argc > 2 && !is_valid_nums(&nums))
		return (1);
	return (0);
}
