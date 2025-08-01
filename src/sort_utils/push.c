/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/01 17:52:03 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_all *all)
{
	t_node	*tmp;

	if (all->stack_b->size == 0)
		return (NULL);
	tmp = remove_first(all->stack_b);
	add_first(all->stack_a, tmp);
	return ("pa\n");
}

char	*push_b(t_all *all)
{
	t_node	*tmp;
	ft_printf("print push b start\n");
	if (all->stack_a->size == 0)
		return (NULL);
	tmp = remove_first(all->stack_a);
	add_first(all->stack_b, tmp);
	ft_printf("print push b end\n");
	return ("pb\n");
}
