/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/16 13:37:20 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_all *all)
{
	t_node	*tmp;

	// ft_printf("print push a start\n");
	if (all->stack_b->size == 0)
		return ;
	tmp = remove_head(all->stack_b);
	// ft_printf("tmp = %d\n", tmp->value);
	add_front(all->stack_a, tmp);
	// ft_printf("putted to a = %d\n", tmp->value);
	// ft_printf("STACK_B HEAD = %d\n", all->stack_b->head->value);
	// ft_printf("STACK_A HEAD = %d\n", all->stack_a->head->value);
	// ft_printf("print push a end\n");
	// ft_printf("------\n");
}

void	push_b(t_all *all)
{
	t_node	*tmp;

	// ft_printf("print push b start\n");
	// ft_printf("A LIST SIZE = %d\n", all->stack_a->size);
	if (all->stack_a->size == 0)
		return ;
	tmp = remove_head(all->stack_a);
	// ft_printf("b LIST SIZE = %d\n", all->stack_b->size);
	add_front(all->stack_b, tmp);

	// ft_printf("print push b end\n");
	// ft_printf("------\n");
}
