/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/12 11:16:29 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_all *all)
{
	int		n;
	// t_node	*ptr_head_a;
	// t_node	*ptr_head_b;
	
	n = all->stack_a->size;
	// printf("stack size = %d\n", n);
	if (n > 5)
		sort_big(all);
	else if (n == 5)
		sort5(all);
	else if (n == 4)
		sort4(all);
	else if (n == 3)
		sort3(all->stack_a, 'a');
	else if (n == 2)
		ft_printf("%s", swap(all->stack_a, 'a'));
	// ptr_head_a = all->stack_a->head;
	// while (ptr_head_a)
	// {
	// 	ft_printf("main stack a after [%d] = %d flag = %d\n", ptr_head_a->order,
	// 		ptr_head_a->value, ptr_head_a->flag);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("main stack b after [%d] = %d flag = %d\n", ptr_head_b->order,
	// 		ptr_head_b->value, ptr_head_b->flag);
	// 	ptr_head_b = ptr_head_b->next;
	// }
	free_all(all);
}
