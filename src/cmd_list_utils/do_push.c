/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:16:50 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 13:22:00 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push_a(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	push_a(all);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(PA);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}

void	do_push_b(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	push_b(all);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(PB);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}
