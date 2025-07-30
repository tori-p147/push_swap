/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 18:21:05 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_all *all)
{
	int	n;

	n = all->stack_a->size;
	printf("%d\n", n);
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
		
	}
		// sort3(all);
	else if (n == 2)
		ft_printf("%s", rotate(all->stack_a, 'a'));
}
