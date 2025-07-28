/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:17:34 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 18:18:19 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_nums nums;

	if (argc == 1)
	{
		ft_printf("wrong args\n");
		return (1);
	}
	if (argc == 2)
	{
		nums.nums = parse_nums(&nums, argv[1]);
		if (!nums.nums)
			return (1);
		nums.allocated = true;
		if (!is_valid_nums(&nums))
			return (1);
		return (0);
	}
	nums.nums = argv + 1;
	nums.allocated = false;
	if (argc > 2 && !is_valid_nums(&nums))
		return (1);
	return (0);
}
