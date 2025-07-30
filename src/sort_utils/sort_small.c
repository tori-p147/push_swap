/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:56:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 23:13:32 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int get_min()
// {

// }

void	sort3(t_all *all)
{
	t_node	*ptr_head;
	t_node	*min;

	ptr_head = all->stack_a->head;
	min = all->stack_a->head;
	while (++ptr_head)
	{
		if (ptr_head->value < min->value)
			min = ptr_head->value;
		ptr_head++;
	}
	ft_printf("min = %d\n", min->value);
}
