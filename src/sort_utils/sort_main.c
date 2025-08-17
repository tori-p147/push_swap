/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/16 14:06:33 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_all *all)
{
	int	n;

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
		sort3(all->stack_a);
	else if (n == 2)
	{
		swap(all->stack_a);
		ft_printf("%s", SA);
	}
	free_all(all);
}
