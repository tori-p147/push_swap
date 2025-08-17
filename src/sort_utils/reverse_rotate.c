/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/16 13:54:48 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_llist *stack)
{
	t_node *last;

	if (!stack)
		return ;
	if (stack->size == 2)
		swap(stack);
	else
	{
		last = stack->tail;
		stack->tail = last->prev;
		stack->tail->next = NULL;
		last->next = stack->head;
		last->prev = NULL;
		stack->head = last;
	}
	// t_node *ptr;
	// ptr = stack->head;
	// ft_printf("head after rra = %p\n", ptr);
	// while (ptr)
	// {
	// 	ft_printf("stack_a [%d] = %d with next = %p\n", ptr->order, ptr->value, ptr->next);
	// 	ptr = ptr->next;
	// }
}
