/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:56:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:49:26 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_all *all, t_cmd_list *cmd_list)
{
	int	first;
	int	second;
	int	third;

	first = all->stack_a->head->order;
	second = all->stack_a->head->next->order;
	third = all->stack_a->head->next->next->order;
	if (first > second && second > third)
	{
		do_swap_a(all, cmd_list);
		do_reverse_rotate_a(all, cmd_list);
	}
	else if (first > second && third < first)
		do_rotate_a(all, cmd_list);
	else if (first > second && third > first)
		do_swap_a(all, cmd_list);
	else if (first < second && first > third)
		do_reverse_rotate_a(all, cmd_list);
	else if (first < second && first < third)
	{
		do_swap_a(all, cmd_list);
		do_rotate_a(all, cmd_list);
	}
}

void	sort4(t_all *all, t_cmd_list *cmd_list)
{
	shift_min_to_head(all, cmd_list);
	sort_rest(all, 3, cmd_list);
}

void	sort_rest(t_all *all, int unsort_nums_amount, t_cmd_list *cmd_list)
{
	int	*arr;

	arr = create_orders_arr(all->stack_a);
	if (!arr)
	{
		free_all(all);
		return ;
	}
	if (!is_sorted(arr, all->stack_a->size))
	{
		do_push_b(all, cmd_list);
		if (unsort_nums_amount == 3)
			sort3(all, cmd_list);
		else if (unsort_nums_amount == 4)
			sort4(all, cmd_list);
		do_push_a(all, cmd_list);
	}
	free(arr);
}

void	sort5(t_all *all, t_cmd_list *cmd_list)
{
	shift_min_to_head(all, cmd_list);
	sort_rest(all, 4, cmd_list);
}
