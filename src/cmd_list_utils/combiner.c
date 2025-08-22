/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combiner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:20:45 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 15:09:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_strdup(t_all *all, t_cmd_list *cmd_list)
{
	if (!cmd_list->str_arr[cmd_list->cmd_i])
		exit_error_big_sort(all, cmd_list);
}

void	combine_cmd_list(t_cmd_list *cmd_list)
{
	int	i;
	int	j;
	int	pb_count;
	int	pa_count;
	int	shift;
	int	del;
	int	tail;

	i = 1;
	pb_count = 0;
	pa_count = 0;
	// ft_printf("start coomb\n");
	while (i < cmd_list->cmd_i - 1 && cmd_list->str_arr[i] && cmd_list->str_arr[i + 1])
	{
		if ((ft_strncmp(cmd_list->str_arr[i], "ra\n", 4) == 0
				&& ft_strncmp(cmd_list->str_arr[i - 1], "rb\n", 4) == 0)
			|| (ft_strncmp(cmd_list->str_arr[i], "rb\n", 4) == 0
				&& ft_strncmp(cmd_list->str_arr[i - 1], "ra\n", 4) == 0))
		{
			free(cmd_list->str_arr[i - 1]);
			cmd_list->str_arr[i - 1] = ft_strdup("rr\n");
			free(cmd_list->str_arr[i]);
			j = i;
			while (j < cmd_list->cmd_i - 1)
			{
				cmd_list->str_arr[j] = cmd_list->str_arr[j + 1];
				j++;
			}
			cmd_list->str_arr[j] = NULL;
			cmd_list->cmd_i--;
		}
		else if ((ft_strncmp(cmd_list->str_arr[i], "rb\n", 3) == 0
				&& ft_strncmp(cmd_list->str_arr[i - 1], "rrb\n", 3) == 0)
			|| (ft_strncmp(cmd_list->str_arr[i], "rrb\n", 3) == 0
				&& ft_strncmp(cmd_list->str_arr[i - 1], "rb\n", 3) == 0))
		{
			free(cmd_list->str_arr[i - 1]);
			free(cmd_list->str_arr[i]);
			j = i - 1;
			while (j < cmd_list->cmd_i - 1)
			{
				cmd_list->str_arr[j] = cmd_list->str_arr[j + 2];
				j++;
			}
			cmd_list->str_arr[j] = NULL;
			cmd_list->cmd_i -= 2;
		}
		else if (ft_strncmp(cmd_list->str_arr[i], "pb\n", 3) == 0)
		{
			pb_count = 1;
			pa_count = 0;
			j = i;
			while (j < cmd_list->cmd_i)
			{
				if (ft_strncmp(cmd_list->str_arr[j], "pb\n", 3) == 0)
					pb_count++;
				else if (ft_strncmp(cmd_list->str_arr[j], "pa\n", 3) == 0)
					pa_count++;
				else
					break ;
				j++;
			}
			shift = get_min_count(pb_count, pa_count) * 2;
			if (shift > 0)
			{
				del = 0;
				while (del < shift)
				{
					free(cmd_list->str_arr[i + del]);
					del++;
				}
				ft_memmove(&cmd_list->str_arr[i], &cmd_list->str_arr[i + shift],
					sizeof(char *) * (cmd_list->cmd_i - (i + shift)));
				tail = cmd_list->cmd_i - shift;
				while (tail < cmd_list->cmd_i)
				{
					cmd_list->str_arr[tail] = NULL;
					tail++;
				}
				cmd_list->cmd_i -= shift;
			}
			else
				i++;
		}
		else if (ft_strncmp(cmd_list->str_arr[i], "pa\n", 3) == 0)
		{
			pa_count = 1;
			pb_count = 0;
			j = i;
			while (j < cmd_list->cmd_i)
			{
				if (ft_strncmp(cmd_list->str_arr[j], "pa\n", 3) == 0)
					pa_count++;
				else if (ft_strncmp(cmd_list->str_arr[j], "pb\n", 3) == 0)
					pb_count++;
				else
					break ;
				j++;
			}
			shift = get_min_count(pb_count, pa_count) * 2;
			if (shift > 0)
			{
				del = 0;
				while (del < shift)
				{
					free(cmd_list->str_arr[i + del]);
					del++;
				}
				ft_memmove(&cmd_list->str_arr[i], &cmd_list->str_arr[i + shift],
					sizeof(char *) * (cmd_list->cmd_i - (i + shift)));
				tail = cmd_list->cmd_i - shift;
				while (tail < cmd_list->cmd_i)
				{
					cmd_list->str_arr[tail] = NULL;
					tail++;
				}
				cmd_list->cmd_i -= shift;
			}
			else
				i++;
		}
		else
			i++;
	}
}
