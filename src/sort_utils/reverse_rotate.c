/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/20 19:19:02 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_llist *stack)
{
	t_node *last;
	
	if (!stack || stack->size <= 1)
		return ;
	// if (stack->size == 2)
	// 	swap(stack);
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	last->prev = NULL;
	stack->head = last;
}
