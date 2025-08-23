/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:43:00 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_llist *stack)
{
	t_node	*last;

	if (!stack || stack->size <= 1)
		return ;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	last->prev = NULL;
	stack->head = last;
}
