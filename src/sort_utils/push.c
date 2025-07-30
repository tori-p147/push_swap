/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:21:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 17:40:16 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_all *all)
{
	t_node	*tmp;

	tmp = remove_front(all->stack_b);
	add_front(all->stack_a, tmp);
	return ("pa");
}

char	*push_b(t_all *all)
{
	t_node	*tmp;

	tmp = remove_front(all->stack_a);
	add_front(all->stack_b, tmp);
	return ("pb");
}
