/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/05 13:36:34 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_all *all)
{
	t_node	*tmp;
	// t_node *ptr_head;

	ft_printf("print push a start\n");
	if (all->stack_b->size == 0)
		return (NULL);
	tmp = remove_first(all->stack_b);
	// ft_printf("tmp = %d\n", tmp->value);
	add_front(all->stack_a, tmp);
	ft_printf("putted to a = %d\n", tmp->value);
	// ptr_head = all->stack_b->head;
	// while (ptr_head)
	// {
	// 	ft_printf("b POPED [%d] = %d next = %p\n", ptr_head->order, ptr_head->value, ptr_head->next);
	// 	ptr_head = ptr_head->next;
	// }
	// ft_printf("STACK_B HEAD = %d\n", all->stack_b->head->value);
	// ft_printf("STACK_A HEAD = %d\n", all->stack_a->head->value);
	return ("pa\n");
}

char	*push_b(t_all *all)
{
	t_node	*tmp;
	t_node *ptr_head;
	// ft_printf("print push b start\n");
	// ft_printf("A LIST SIZE = %d\n", all->stack_a->size);
	if (all->stack_a->size == 0)
		return (NULL);
	tmp = remove_first(all->stack_a);
	// ft_printf("b LIST SIZE = %d\n", all->stack_b->size);
	add_front(all->stack_b, tmp);
	ft_printf("putted to b\n");
	ptr_head = all->stack_b->head;
	while (ptr_head)
	{
		ft_printf("push_b [%d] = %d next = %p\n", ptr_head->order, ptr_head->value, ptr_head->next);
		ptr_head = ptr_head->next;
	}
	// ft_printf("print push b end\n");
	return ("pb\n");
}
