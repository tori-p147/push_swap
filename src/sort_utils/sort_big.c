/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:52:18 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_process(t_all *all, t_cmd_list *cmd_list)
{
	int	size;
	int	curr_order;

	all->mid = all->max / 2 + all->next;
	size = all->stack_a->size;
	while (cmd_list->cmd_i < size)
	{
		curr_order = all->stack_a->head->order;
		if (curr_order <= all->mid)
		{
			do_push_b(all, cmd_list);
			all->stack_b->head->flag = all->flag + 1;
		}
		else
			do_rotate_a(all, cmd_list);
	}
	all->flag = 1;
}

void	process_a_flag(t_all *all, t_cmd_list *cmd_list)
{
	int	max_flag;

	max_flag = find_max_flag(all->stack_a);
	while (all->stack_a->head && all->stack_a->head->flag == max_flag)
	{
		if (all->stack_a->head->order == all->next)
		{
			do_rotate_a(all, cmd_list);
			all->next++;
			all->stack_a->tail->flag = -1;
			continue ;
		}
		do_push_b(all, cmd_list);
		if (max_flag == 0)
			all->stack_b->head->flag = all->flag;
	}
}

void	move_to_top_b(t_all *all, t_cmd_list *cmd_list)
{
	t_node	*curr;
	int		next_pos;
	int		size;

	size = all->stack_b->size;
	if (size == 2 && all->stack_b->head->order > all->stack_b->tail->order)
	{
		do_swap_b(all, cmd_list);
		return ;
	}
	curr = all->stack_b->head;
	next_pos = 0;
	while (curr)
	{
		if (curr->order == all->next)
			break ;
		next_pos++;
		curr = curr->next;
	}
	if (next_pos == 0)
		return ;
	if (next_pos <= size / 1.5)
		do_rotate_b(all, cmd_list);
	else
		do_reverse_rotate_b(all, cmd_list);
}

void	do_push_rotate_a(t_all *all, t_cmd_list *cmd_list)
{
	do_push_a(all, cmd_list);
	all->next++;
	if (is_next_found(all->stack_b, all->next))
		move_to_top_b(all, cmd_list);
	do_rotate_a(all, cmd_list);
	all->stack_a->tail->flag = -1;
}

void	process_b(t_all *all, t_cmd_list *cmd_list, int current_flag)
{
	t_node	*curr;
	int		size;

	while (count_flag_elements(all->stack_b, current_flag) > 0)
	{
		all->mid = calculate_mid_order(all->stack_b, current_flag, all->next);
		size = count_flag_elements(all->stack_b, current_flag);
		while (size-- > 0)
		{
			curr = all->stack_b->head;
			if (curr->order == all->next)
				do_push_rotate_a(all, cmd_list);
			else if (curr->order >= all->mid)
			{
				do_push_a(all, cmd_list);
				all->stack_a->head->flag = all->flag + 1;
			}
			else if (is_next_found(all->stack_b, all->next))
				move_to_top_b(all, cmd_list);
			else
				process_a_flag(all, cmd_list);
		}
		if (count_flag_elements(all->stack_b, current_flag) == 0)
			current_flag++;
	}
}
