/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/03 19:47:06 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_all *all)
{
	int		n;
	t_node	*ptr_head;

	n = all->stack_a->size;
	printf("stack size = %d\n", n);
	ptr_head = all->stack_a->head;
	while (ptr_head)
	{
		ft_printf("main stack a [%d] = %d next = %p\n", ptr_head->order, ptr_head->value, ptr_head->next);
		ptr_head = ptr_head->next;
	}
	if (n > 5)
	{
	}
	else if (n == 5)
	{
	}
	else if (n == 4)
		sort4(all);
	else if (n == 3)
		sort3(all);
	else if (n == 2)
		ft_printf("%s", swap(all->stack_a, 'a'));
	ptr_head = all->stack_a->head;
	while (ptr_head)
	{
		ft_printf("main stack a [%d] = %d next = %p\n", ptr_head->order, ptr_head->value, ptr_head->next);
		ptr_head = ptr_head->next;
	}
}
