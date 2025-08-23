/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:48:16 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:55:03 by vmatsuda         ###   ########.fr       */
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
