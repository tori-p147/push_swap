/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:56:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 21:31:03 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nums(t_nums *nums)
{
	char	**ptr;

	if (!nums->allocated)
		return ;
	ptr = nums->nums;
	while (*nums->nums)
	{
		// printf("%s\n", *nums);
		free(*nums->nums);
		nums->nums++;
	}
	free(ptr);
	ptr = NULL;
	// printf("%p\n", ptr);
}

void	free_list(t_llist *list)
{
	t_node	*head_ptr;
	t_node	*next_ptr;

	if (!list)
		return ;
	head_ptr = list->head;
	while (head_ptr)
	{
		next_ptr = head_ptr->next;
		free(head_ptr);
		head_ptr = next_ptr;
	}
	free(list);
}

void	free_all(t_all *all)
{
	if (!all)
		return ;
	free_list(all->stack_a);
	free_list(all->stack_b);
	all->min_a = 0;
	all->med = 0;
	free(all);
}
