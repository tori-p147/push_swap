/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/09 21:43:16 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_strdup(t_all *all, char **str_arr, int cmd_i)
{
	if (!str_arr[cmd_i])
		exit_error_big_sort(all, str_arr);
}

void	process_a(t_all *all)
{
	char	**str_arr;
	t_llist	*stack;
	int		curr_order;
	int		curr_flag;
	int		cmd_i;
	int		size;
	char	**ptr_arr;

	cmd_i = 0;
	all->mid = calculate_mid_order(all->stack_a, all->flag);
	if (all->mid == -1)
		exit_error_big_sort(all, NULL);
	else if (all->mid == 0)
		return ;
	str_arr = malloc(sizeof(char *) * (all->stack_a->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL);
	stack = all->stack_a;
	size = stack->size;
	while (cmd_i < size)
	{
		curr_order = stack->head->order;
		curr_flag = stack->head->flag;
		// ft_printf("curr = %d\n", curr_order);
		if (curr_order <= all->mid && (curr_flag == all->flag || (all->flag == 0
					&& curr_flag == 0)))
		{
			str_arr[cmd_i] = ft_strdup(push_b(all));
			all->stack_b->head->flag++;
		}
		else if (curr_order == all->next)
		{
			str_arr[cmd_i] = ft_strdup(rotate(stack, 'a'));
			all->next++;
			all->stack_a->tail->flag = 0;
		}
		else
			str_arr[cmd_i] = ft_strdup(rotate(stack, 'a'));
		check_strdup(all, str_arr, cmd_i);
		cmd_i++;
	}
	str_arr[cmd_i] = NULL;
	ptr_arr = str_arr;
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr);
}

int	count_flag_elements(t_llist *stack, int flag)
{
	t_node	*ptr_head;
	int		count;

	count = 0;
	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->flag == flag)
			count++;
		ptr_head = ptr_head->next;
	}
	// ft_printf("count %d\n", count);
	return (count);
}

int	calculate_mid_order(t_llist *stack, int flag)
{
	int		mid;
	t_node	*ptr_head;
	int		*orders;
	int		count;
	int		i;
	t_array	flag_nodes;

	count = 0;
	i = 0;
	count = count_flag_elements(stack, flag);
	// ft_printf("count for mid = %d\n", count);
	if (count == 0)
		return (0);
	orders = malloc(sizeof(int) * count);
	if (!orders)
		return (-1);
	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->flag == flag)
			orders[i++] = ptr_head->order;
		ptr_head = ptr_head->next;
	}
	flag_nodes.ints = orders;
	flag_nodes.length = count;
	sort(&flag_nodes);
	mid = orders[count / 2];
	free(flag_nodes.ints);
	// ft_printf("mid order for count %d = [%d]\n", count, mid);
	return (mid);
}

void	process_b(t_all *all)
{
	t_node	*curr;
	int		cmd_i;
	// char	**str_arr;
	// char	**ptr_arr;
	int		flag_nodes;
	int		current_flag;

	current_flag = all->flag;
	// ft_printf("process b start\n");
	all->mid = calculate_mid_order(all->stack_b, current_flag);
	if (all->mid == -1)
		exit_error_big_sort(all, NULL);
	else if (all->mid == 0)
		return ;
	// str_arr = malloc(sizeof(char *) * (all->stack_b->size * 2 + 1));
	// if (!str_arr)
	// 	exit_error_big_sort(all, NULL);
	curr = all->stack_b->head;
	flag_nodes = count_flag_elements(all->stack_b, current_flag);
	cmd_i = 0;
	while (flag_nodes > 0)
	{
		// ft_printf("count flag nodes %d in while loop\n", flag_nodes);
		curr = all->stack_b->head;
		// ft_printf("NEXT = [%d] MID = %d all.flag = %d curr = [%d] flag =%d next = %p\n", all->next, all->mid, all->flag, curr->order,
		// 	curr->flag, curr->next);
		if (curr->order == all->next)
		{
			if (curr->flag == current_flag)
				flag_nodes--;
			ft_printf("%s",push_a(all));
			// check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			ft_printf("%s",rotate(all->stack_a, 'a'));
			// check_strdup(all, str_arr, cmd_i);
			all->next++;
			cmd_i++;
			all->stack_a->tail->flag = 0;
		}
		else if (curr->flag == current_flag)
		{
			if (curr->order >= all->mid)
			{
				ft_printf("%s",push_a(all));
				// check_strdup(all, str_arr, cmd_i);
				all->stack_a->head->flag = all->flag + 1;
				flag_nodes--;
				cmd_i++;
			}
			else
			{
				ft_printf("%s",rotate(all->stack_b, 'b'));
				// check_strdup(all, str_arr, cmd_i);
				cmd_i++;
			}
		}
		else
		{
			ft_strdup(rotate(all->stack_b, 'b'));
			// check_strdup(all, str_arr, cmd_i);
			cmd_i++;
		}
	}
	// str_arr[cmd_i] = NULL;
	// ptr_arr = str_arr;
	// while (*str_arr)
	// {
	// 	ft_printf("%s", *str_arr);
	// 	str_arr++;
	// }
	// free_strs(ptr_arr);
}

int	stack_contains_flag(t_llist *stack, int flag)
{
	t_node	*ptr_head;

	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->flag == flag)
			return (1);
		ptr_head = ptr_head->next;
	}
	return (0);
}

// ./push_swap 9 6 3 13 7 11 2 15 1 10 5 12 4 14 8
void	sort_big(t_all *all)
{
	// t_node	*ptr_head_a;
	// t_node	*ptr_head_b;
	// int i;

	// i = 0;
	while (all->stack_b->size != 0 || stack_contains_flag(all->stack_a, all->flag))
	{
		// ft_printf("current next = %d, flag = %d\n", all->next, all->flag);
		process_a(all);
		// ptr_head_a = all->stack_a->head;
	// 	while (ptr_head_a)
	// {
	// 	ft_printf("stack a before proess b [%d] = %d flag = %d\n", ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("stack b after proess b [%d] = %d flag = %d\n", ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
	// 	ptr_head_b = ptr_head_b->next;
	// }
	// 	ft_printf("current next = %d, flag = %d\n", all->next, all->flag);
		process_b(all);
		if (!stack_contains_flag(all->stack_b, all->flag) && !stack_contains_flag(all->stack_a, all->flag)) 
        	all->flag++;
		// ptr_head_a = all->stack_a->head;
		// i++;
	// 	ft_printf("loop %d result = %d, flag = %d\n", i, all->next, all->flag);
	// while (ptr_head_a)
	// {
	// 	ft_printf("stack a after proess b[%d] = %d flag = %d\n", ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("stack b after proess b[%d] = %d flag = %d\n", ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
	// 	ptr_head_b = ptr_head_b->next;
	// }
	// }
	}
}
