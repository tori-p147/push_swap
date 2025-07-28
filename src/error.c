/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:33:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 18:24:28 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int return_error(char *msg, t_nums *nums, int *ints)
{
	if (msg)
		ft_printf("Error: %s", msg);
	if (nums)
		free_nums(nums);
	if (ints)
		free(ints);
	return (0);
}

