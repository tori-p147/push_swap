/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:19:28 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:26:32 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_llist *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*second;

	if (!stack)
		return ;
	if (stack->size > 1)
	{
		first = stack->head;
		last = stack->tail;
		second = stack->head->next;
		second->prev = NULL;
		stack->head = second;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		stack->tail = first;
	}
}
