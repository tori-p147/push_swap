/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/31 18:01:30 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_all *all)
{
	int		n;
	t_node	*ptr_head;
	// t_node	*ptr_next;

	n = all->stack_a->size;
	printf("stack size = %d\n", n);
	if (n > 5)
	{
	}
	else if (n == 5)
	{
	}
	else if (n == 4)
	{
	}
	else if (n == 3)
	{
		sort3(all);
	}
	else if (n == 2)
		ft_printf("%s", swap(all->stack_a, 'a'));
	ptr_head = all->stack_a->head;
	while (ptr_head)
	{
		ft_printf("stack a [%d] = %d next = %p\n", ptr_head->order, ptr_head->value, ptr_head->next);
		ptr_head = ptr_head->next;
	}
}
