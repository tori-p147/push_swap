/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/01 22:24:50 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_all *all)
{
	t_node	*tmp;

	ft_printf("print push a start\n");
	if (all->stack_b->size == 0)
		return (NULL);
	tmp = remove_first(all->stack_b);
	ft_printf("tmp = %d\n", tmp->value);
	add_front(all->stack_a, tmp);
	return ("pa\n");
}

char	*push_b(t_all *all)
{
	t_node	*tmp;
	ft_printf("print push b start\n");
	if (all->stack_a->size == 0)
		return (NULL);
	tmp = remove_first(all->stack_a);
	add_front(all->stack_b, tmp);
	ft_printf("print push b end\n");
	return ("pb\n");
}
