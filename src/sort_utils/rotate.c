/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:19:28 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/05 15:10:24 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate(t_llist *stack, char stack_name)
{
	t_node	*first;
	t_node	*last;
	t_node	*second;

	// ft_printf("start rotate\n");
	// ft_printf("head stack a = %d\n", stack->head->order);
	if (!stack)
		return (NULL);
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
	ft_printf("rotate %c\n", stack_name);
	t_node *ptr_head;
	ptr_head = stack->head;
	while (ptr_head)
	{
		ft_printf("main stack %c after [%d] = %d next = %p\n", stack_name, ptr_head->order, ptr_head->value, ptr_head->next);
		ptr_head = ptr_head->next;
	}
	if (stack_name == 'a')
		return ("ra\n");
	return ("rb\n");
}
