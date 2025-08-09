/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:06 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/09 20:22:33 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*reverse_rotate(t_llist *stack, char stack_name)
{
	t_node *last;

	if (!stack)
		return (NULL);
	if (stack->size == 2)
		swap(stack, stack_name);
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
	if (stack_name == 'a')
		return ("rra\n");
	return ("rrb\n");
}
