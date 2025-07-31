/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:56:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/31 18:40:12 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min(t_llist *stack_a)
{
	t_node	*ptr_head;
	t_node	*min;

	ptr_head = stack_a->head;
	min = stack_a->head;
	ft_printf("ptr_head = %d [%p]\n", ptr_head->value, ptr_head);
	while (ptr_head)
	{
		if (ptr_head->value < min->value)
		{
			min = ptr_head;
			ft_printf("min = %d\n", ptr_head->value);
		}
		ptr_head = ptr_head->next;
	}
	ft_printf("min = %d\n", min->value);
	ft_printf("order = %d\n", min->order);
	return (min);
}

void	sort3(t_all *all)
{
	// t_node	*min;
	ft_printf("start sort3\n");
	if (all->stack_a->head->order == 0)
	{
		ft_printf("%s", reverse_rotate(all->stack_a, 'a'));
		ft_printf("%s", swap(all->stack_a, 'a'));
	}
	else if (all->stack_a->head->order == 1)
	{
		if (all->stack_a->tail->order == 0)
			ft_printf("%s", reverse_rotate(all->stack_a, 'a'));
		else
			ft_printf("%s", swap(all->stack_a, 'a'));
	}
	else
	{
		if (all->stack_a->tail->order == 0)
		{
			ft_printf("%s", swap(all->stack_a, 'a'));
			ft_printf("%s", reverse_rotate(all->stack_a, 'a'));
		}
		else
			ft_printf("%s", rotate(all->stack_a, 'a'));
	}
}
