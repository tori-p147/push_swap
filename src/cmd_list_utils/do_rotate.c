/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:17:14 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:06:10 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_a(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	rotate(all->stack_a);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(RA);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}

void	do_rotate_b(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	rotate(all->stack_b);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(RB);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}

void	do_reverse_rotate_b(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	reverse_rotate(all->stack_b);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(RRB);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}

void	do_reverse_rotate_a(t_all *all, t_cmd_list *cmd_list)
{
	check_capacity(all, cmd_list);
	reverse_rotate(all->stack_a);
	cmd_list->str_arr[cmd_list->cmd_i] = ft_strdup(RRA);
	check_strdup(all, cmd_list);
	cmd_list->cmd_i++;
}
