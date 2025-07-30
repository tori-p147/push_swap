/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:33:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 18:53:59 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int return_error(char *msg, t_nums *nums, int *ints)
{
	ft_printf("Error\n");
	if (nums)
		free_nums(nums);
	if (ints)
		free(ints);
	return (0);
}
