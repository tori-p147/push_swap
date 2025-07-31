/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/31 18:26:26 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*reverse_rotate(t_llist *stack, char stack_name)
{
	t_node *tmp;

	if (!stack)
		return (NULL);
	if (stack->size == 2)
	{
		swap(stack, stack_name);
		return (NULL);
	}
	else
	{
		tmp = stack->head;
		stack->head = stack->tail;
		stack->head->next = tmp;
		stack->head->prev = NULL;
		stack->tail = tmp->next;
		stack->tail->next = NULL;
	}
	if (stack_name == 'a')
		return ("rra\n");
	return ("rrb\n");
}
