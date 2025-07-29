/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:56:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/29 18:28:10 by vmatsuda         ###   ########.fr       */
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

	head_ptr = list->head;
	while (head_ptr)
	{
		next_ptr = list->head->next;
		free(list->head);
		head_ptr = next_ptr;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
