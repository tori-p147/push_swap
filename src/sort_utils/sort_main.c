/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:50:24 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 18:12:45 by vmatsuda         ###   ########.fr       */
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

void	sort_main(t_all *all)
{
	int	n;
	t_cmd_list	cmd_list;
	char		**ptr_arr;

	init_str_arr(all, &cmd_list);
	// t_node	*ptr_head_a;
	// t_node	*ptr_head_b;
	n = all->stack_a->size;
	// printf("stack size = %d\n", n);
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
	// ptr_arr = cmd_list.str_arr;
	// while (*ptr_arr)
	// {
	// 	ft_printf("%s", *ptr_arr);
	// 	ptr_arr++;
	// }
	// ft_printf("cmds bfr= %d\n", cmd_list.cmd_i);
	// combine_cmd_list(&cmd_list);
	ptr_arr = cmd_list.str_arr;
	while (*ptr_arr)
	{
		ft_printf("%s", *ptr_arr);
		ptr_arr++;
	}
	cmd_list.cmd_i = 0;
	while (cmd_list.str_arr[cmd_list.cmd_i])
    	cmd_list.cmd_i++;
	// ft_printf("cmds aft= %d\n", cmd_list.cmd_i);
	free_strs(&cmd_list);
	free_all(all);
}
