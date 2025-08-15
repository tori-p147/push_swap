/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/14 16:06:42 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_all *all)
{
	t_node	*tmp;
	// t_node *ptr_head_a;
	// t_node *ptr_head_b;

	// ft_printf("print push a start\n");
	if (all->stack_b->size == 0)
		return (NULL);
	tmp = remove_head(all->stack_b);
	// ft_printf("tmp = %d\n", tmp->value);
	add_front(all->stack_a, tmp);
	// ft_printf("putted to a = %d\n", tmp->value);
	// ptr_head_a = all->stack_a->head;
	// while (ptr_head_a)
	// {
	// 	ft_printf("stack a [%d] = %d, chunk = %d, next = %p\n", ptr_head_a->order, ptr_head_a->value, ptr_head_a->chunk, ptr_head_a->next);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("stack b [%d] = %d, chunk = %d, next = %p\n", ptr_head_b->order, ptr_head_b->value, ptr_head_b->chunk, ptr_head_b->next);
	// 	ptr_head_b = ptr_head_b->next;
	// }
	// ft_printf("STACK_B HEAD = %d\n", all->stack_b->head->value);
	// ft_printf("STACK_A HEAD = %d\n", all->stack_a->head->value);
	// ft_printf("print push a end\n");
	// ft_printf("------\n");
	return ("pa\n");
}

char	*push_b(t_all *all)
{
	t_node	*tmp;
	// t_node *ptr_head_a;
	// t_node *ptr_head_b;
	// ft_printf("print push b start\n");
	// ft_printf("A LIST SIZE = %d\n", all->stack_a->size);
	if (all->stack_a->size == 0)
		return (NULL);
	tmp = remove_head(all->stack_a);
	// ft_printf("b LIST SIZE = %d\n", all->stack_b->size);
	add_front(all->stack_b, tmp);
	// ft_printf("putted to b\n");
	// ptr_head_a = all->stack_a->head;
	// while (ptr_head_a)
	// {
	// 	ft_printf("stack a [%d] = %d, chunk = %d, next = %p\n", ptr_head_a->order, ptr_head_a->value, ptr_head_a->chunk, ptr_head_a->next);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("stack b [%d] = %d, chunk = %d, next = %p\n", ptr_head_b->order, ptr_head_b->value, ptr_head_b->chunk, ptr_head_b->next);
	// 	ptr_head_b = ptr_head_b->next;
	// }
	// ft_printf("print push b end\n");
	// ft_printf("------\n");
	return ("pb\n");
}
