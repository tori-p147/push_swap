/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:46:40 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_str_arr(t_all *all, t_cmd_list *cmd_list)
{
	cmd_list->capacity = all->stack_a->size + 1;
	cmd_list->str_arr = malloc(sizeof(char *) * cmd_list->capacity);
	if (!cmd_list->str_arr)
		exit_error_big_sort(all, NULL);
	cmd_list->cmd_i = 0;
}

void	sort_big(t_all *all, t_cmd_list *cmd_list)
{
	int	current_flag;

	first_process(all, cmd_list);
	while (!is_sorted_stack(all->stack_a) || all->stack_b->size > 0)
	{
		if (all->stack_b->size > 0)
		{
			all->flag = all->stack_b->head->flag;
			current_flag = all->flag;
			process_b(all, cmd_list, current_flag);
			all->flag = current_flag;
		}
		if (all->stack_b->size == 0)
			process_a_flag(all, cmd_list);
	}
}

void	sort_main(t_all *all)
{
	int			n;
	t_cmd_list	cmd_list;
	int			i;

	init_str_arr(all, &cmd_list);
	n = all->stack_a->size;
	if (n > 5)
		sort_big(all, &cmd_list);
	else if (n == 5)
		sort5(all, &cmd_list);
	else if (n == 4)
		sort4(all, &cmd_list);
	else if (n == 3)
		sort3(all, &cmd_list);
	else if (n == 2)
		do_swap_a(all, &cmd_list);
	cmd_list.str_arr[cmd_list.cmd_i] = NULL;
	i = 0;
	while (i < cmd_list.cmd_i)
	{
		ft_printf("%s", cmd_list.str_arr[i]);
		i++;
	}
	free_strs(&cmd_list);
	free_all(all);
}
