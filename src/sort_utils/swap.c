/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:20:54 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:42:18 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(t_node *first, t_node *second)
{
	int	tmp_value;
	int	tmp_order;
	int	tmp_flag;

	if (!first || !second)
		return ;
	tmp_value = first->value;
	tmp_flag = first->flag;
	tmp_order = first->order;
	first->value = second->value;
	first->order = second->order;
	first->flag = second->flag;
	second->value = tmp_value;
	second->order = tmp_order;
	second->flag = tmp_flag;
}

void	swap(t_llist *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = stack->head->next;
	swap_values(first, second);
}
