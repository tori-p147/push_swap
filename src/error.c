/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:33:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 11:59:26 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_error_big_sort(t_all *all, t_cmd_list *cmd_list)
{
	if (all)
		free_all(all);
	if (cmd_list)
		free_strs(cmd_list);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int	exit_create_list_error(t_all *all, t_llist *stack_a, t_llist *stack_b,
		t_array *ints)
{
	if (ints)
		free(ints->ints);
	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	if (all)
		free_all(all);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int	free_and_return_error_validation(t_nums *nums, int *ints)
{
	write(2, "Error\n", 7);
	if (nums)
		free_nums(nums);
	if (ints)
		free(ints);
	return (0);
}
