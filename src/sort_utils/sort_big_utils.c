/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:51:50 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:43:42 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_min_to_head(t_all *all, t_cmd_list *cmd_list)
{
	int	rra_times;
	int	min_index;

	rra_times = 0;
	min_index = get_min_index(all->stack_a);
	if (min_index == 0)
		return ;
	if (min_index <= all->stack_a->size / 2)
	{
		while (min_index-- > 0)
			do_rotate_a(all, cmd_list);
	}
	else
	{
		rra_times = all->stack_a->size - min_index;
		while (rra_times-- > 0)
			do_reverse_rotate_a(all, cmd_list);
	}
}

int	find_max_flag(t_llist *stack)
{
	t_node	*tmp;
	int		max_flag;

	tmp = stack->head;
	max_flag = 0;
	while (tmp)
	{
		if (tmp->flag > max_flag)
			max_flag = tmp->flag;
		tmp = tmp->next;
	}
	return (max_flag);
}

int	count_flag_elements(t_llist *stack, int flag)
{
	t_node	*ptr_head;
	int		count;

	count = 0;
	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->flag == flag)
			count++;
		ptr_head = ptr_head->next;
	}
	return (count);
}

int	calculate_mid_order(t_llist *stack, int flag, int next)
{
	t_node	*curr;
	int		max;

	curr = stack->head;
	max = next;
	while (curr)
	{
		if (curr->flag == flag && curr->order > max)
			max = curr->order;
		curr = curr->next;
	}
	return ((max - next + 1) / 2 + next);
}

int	is_next_found(t_llist *stack, int next)
{
	t_node	*ptr_head;

	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->order == next)
			return (1);
		ptr_head = ptr_head->next;
	}
	return (0);
}
