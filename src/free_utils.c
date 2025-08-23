/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:56:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:03:35 by vmatsuda         ###   ########.fr       */
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
		free(*nums->nums);
		nums->nums++;
	}
	free(ptr);
	ptr = NULL;
}

void	free_list(t_llist *list)
{
	t_node	*curr;
	t_node	*next_ptr;

	if (!list)
		return ;
	curr = list->head;
	while (curr)
	{
		next_ptr = curr->next;
		free(curr);
		curr = next_ptr;
	}
	free(list);
}

void	free_all(t_all *all)
{
	if (!all)
		return ;
	free_list(all->stack_a);
	free_list(all->stack_b);
	all->mid = 0;
	all->flag = 0;
	all->next = 0;
	free(all);
}

void	free_strs(t_cmd_list *cmd_list)
{
	int	i;

	i = 0;
	while (i < cmd_list->cmd_i)
	{
		free(cmd_list->str_arr[i]);
		i++;
	}
	free(cmd_list->str_arr);
}
