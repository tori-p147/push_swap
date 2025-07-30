/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:19:28 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 17:53:08 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

char	*rotate(t_llist *stack, char stack_name)
{
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack->head;
	stack->head = stack->tail;
	stack->tail = tmp;
	if (stack_name == 'a')
		return ("ra\n");
	return ("rb\n");
}
