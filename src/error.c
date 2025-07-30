/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:33:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 22:51:50 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_and_return_error(t_nums *nums, int *ints)
{
	ft_printf("Error\n");
	if (nums)
		free_nums(nums);
	if (ints)
		free(ints);
	return (0);
}
