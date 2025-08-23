/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:27:06 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_all *all)
{
	t_node	*tmp;

	if (all->stack_b->size == 0)
		return ;
	tmp = remove_head(all->stack_b);
	add_front(all->stack_a, tmp);
}

void	push_b(t_all *all)
{
	t_node	*tmp;

	if (all->stack_a->size == 0)
		return ;
	tmp = remove_head(all->stack_a);
	add_front(all->stack_b, tmp);
}
