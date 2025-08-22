/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:15:40 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 13:22:05 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap_a(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	swap(all->stack_a);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(SA);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}

void	do_swap_b(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	swap(all->stack_b);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(SB);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}
