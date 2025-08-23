/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:40:33 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 17:54:49 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_strdup(t_all *all, t_cmd_list *cmd_list)
{
	if (!cmd_list->str_arr[cmd_list->cmd_i])
		exit_error_big_sort(all, cmd_list);
}

void	check_capacity(t_all *all, t_cmd_list *cmd_list)
{
	int		new_capacity;
	char	**new_arr;
	int		i;

	new_arr = NULL;
	new_capacity = cmd_list->capacity * 2;
	i = 0;
	if (cmd_list->cmd_i >= cmd_list->capacity)
	{
		new_arr = malloc(sizeof(char *) * new_capacity);
		if (!new_arr)
			exit_error_big_sort(all, NULL);
		while (i < cmd_list->cmd_i)
		{
			new_arr[i] = cmd_list->str_arr[i];
			i++;
		}
		while (i < new_capacity)
			new_arr[i++] = NULL;
		free(cmd_list->str_arr);
		cmd_list->str_arr = new_arr;
		cmd_list->capacity = new_capacity;
	}
}
