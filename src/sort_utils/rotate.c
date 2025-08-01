/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:19:28 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/01 16:13:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate(t_llist *stack, char stack_name)
{
	t_node	*first;
	t_node	*last;
	t_node	*second;

	ft_printf("start rotate\n");
	if (!stack)
		return (NULL);
	first = stack->head;
	last = stack->tail;
	second = stack->head->next;
	second->prev = NULL;
	stack->head = second;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->tail = first;
	if (stack_name == 'a')
		return ("ra\n");
	return ("rb\n");
}
