/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:56:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/21 22:27:31 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_llist *stack_a)
{
	t_node	*min;
	t_node	*ptr_head;
	int		min_index;
	int		i;

	i = 0;
	min = stack_a->head;
	min_index = 0;
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->value < min->value)
		{
			min = ptr_head;
			min_index = i;
		}
		ptr_head = ptr_head->next;
		i++;
	}
	return (min_index);
}

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

int	*create_orders_arr(t_llist *stack)
{
	int		*arr;
	t_node	*ptr_head;
	int		*ptr_arr;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	ptr_head = stack->head;
	ptr_arr = arr;
	while (ptr_head)
	{
		*arr++ = ptr_head->order;
		ptr_head = ptr_head->next;
	}
	return (ptr_arr);
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
