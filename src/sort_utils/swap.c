/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:20:54 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/06 15:29:35 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(t_node *first, t_node *second)
{
	int	tmp_value;
	int	tmp_order;
	int	tmp_chunk;

	ft_printf("first = %p\n", first);
	ft_printf("second = %p\n", second);
	if(!first || !second)
		return ;
	tmp_value = first->value;
	tmp_chunk = first->chunk;
	tmp_order = first->order;
	first->value = second->value;
	first->order = second->order;
	first->chunk = second->chunk;
	second->value = tmp_value;
	second->order = tmp_order;
	second->chunk = tmp_chunk;
}

char	*swap(t_llist *stack, char stack_name)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return (NULL);
	first = stack->head;
	second = stack->head->next;
	swap_values(first, second);
	if (stack_name == 'a')
		return ("sa\n");
	return ("sb\n");
}
