/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:17:34 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/25 18:50:33 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
    char **nums;

	if (argc == 1)
	{
		error();
		return (1);
	}
	else if (argc == 2)
	{
		nums = parse_nums(argv[1]);
        if (!nums)
            return (1);
        if (!validate_nums(nums))
            return (1);
        return (0);
	}
	else if (argc > 2 && !validate_nums(argv))
	{
		error();
		return (1);
	}
	return (0);
}
