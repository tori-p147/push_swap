/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/13 12:39:09 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_strdup(t_all *all, char **str_arr, int cmd_i)
{
	if (!str_arr[cmd_i])
		exit_error_big_sort(all, str_arr);
}

int	is_next_blocked(t_llist *stack, int next)
{
	t_node	*ptr_head;
	t_node	*ptr_next;

	ptr_next = NULL;
	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->order == next)
		{
			ptr_next = ptr_head;
			break ;
		}
		ptr_head = ptr_head->next;
	}
	if (!ptr_next)
		return (1);
	while (ptr_next)
	{
		if (ptr_next->order < next)
			return (1);
		ptr_next = ptr_next->next;
	}
	return (0);
}

int	first_process(t_all *all)
{
	int		size;
	int		cmd_i;
	int		curr_order;
	char	**str_arr;
	char	**ptr_arr;

	all->max = all->stack_a->size;
	// ft_printf("NEW MAX %d NEXT %d\n", all->max, all->next);
	// if (all->flag != 0)
	// 	all->mid = all->max / 2 + all->next;
	all->mid = all->max / 2 + all->next;
	// ft_printf("mid in first proc %d \n", all->mid);
	str_arr = malloc(sizeof(char *) * (all->stack_a->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL);
	size = all->stack_a->size;
	cmd_i = 0;
	while (cmd_i < size)
	{
		curr_order = all->stack_a->head->order;
		if (curr_order <= all->mid)
		{
			str_arr[cmd_i] = ft_strdup(push_b(all));
			check_strdup(all, str_arr, cmd_i);
			all->stack_b->head->flag = all->flag + 1;
		}
		else
		{
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			check_strdup(all, str_arr, cmd_i);
		}
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
	all->flag = 1;
	return (cmd_i);
}

void	process_a2(t_all *all)
{
	t_llist	*stack;
	int		cmd_i;
	int		size;
	char	**ptr_arr;
	char	**str_arr;

	// t_node	*ptr_head_a;
	// t_node	*ptr_head_b;
	cmd_i = 0;
	all->max = all->stack_a->size;
	all->mid = all->stack_a->size / 2 + all->next;
	// ft_printf("curr mid %d\n", all->mid);
	if (all->mid == 0)
		return ;
	str_arr = malloc(sizeof(char *) * (all->stack_a->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL);
	stack = all->stack_a;
	size = stack->size - all->next;
	// ft_printf("FINAL stack size = %d - next %d\n", size, all->next);
	while (cmd_i < size)
	{
		// ft_printf("curr = [%d], flag = %d\n", curr->order, curr->flag);
		str_arr[cmd_i] = ft_strdup(push_b(all));
		all->stack_b->head->flag = all->flag;
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

void	process_a_flag(t_all *all)
{
	t_node	*curr;
	int		cmd_i;
	char	**str_arr;
	char	**ptr_arr;

	// if (!stack_contains_next(all->stack_a, all->flag, all->next))
	// 	move_next_to_top(all->stack_a, all->next);
	cmd_i = 0;
	// ft_printf("loop %d result = %d, flag = %d\n", cmd_i, all->next, all->flag);
	cmd_i = 0;
	str_arr = malloc(sizeof(char *) * (all->stack_a->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL);
	curr = all->stack_a->head;
	while (curr)
	{
		// Обрабатываем элемент с order == next вне зависимости от флага
		if (curr->order == all->next)
		{
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			all->next++;
			all->stack_a->tail->flag = 0;
			cmd_i++;
			curr = all->stack_a->head;
			continue ;
		}
		// Если элемент с нужным флагом - пушим в B
		if (curr->flag == all->flag)
		{
			// ft_printf("curr = [%d], flag = %d\n", curr->order, curr->flag);
			str_arr[cmd_i] = ft_strdup(push_b(all));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			curr = all->stack_a->head;
		}
		else
		{
			// Если элемент не с текущим флагом и не next — выходим из цикла,
			//	чтобы не застрять
			break ;
		}
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

int	calculate_mid_order(t_all *all, t_llist *stack)
{
	// ft_printf("max %d\n", all->max);
	if (!stack || stack->size == 0)
		return (0);
	if (all->max <= all->next)
		return (all->next);
	// ft_printf("mid  = %d - %d / 2 + %d\n", all->max, all->next, all->next);
	return (((all->max - all->next) + 1) / 2 + all->next);
}

void	update_flag(t_all *all)
{
	t_node	*curr;
	int		min_flag;

	curr = all->stack_a->head;
	min_flag = INT_MAX;
	while (curr)
	{
		if (curr->order >= all->next && curr->flag < min_flag)
			min_flag = curr->flag;
		curr = curr->next;
	}
	if (min_flag != INT_MAX)
		all->flag = min_flag;
}

void	process_b(t_all *all)
{
	t_node	*curr;
	int		cmd_i;
	int		flag_nodes;
	int		current_flag;
	char	**str_arr;
	char	**ptr_arr;

	// t_node	*ptr_head_a;
	// t_node	*ptr_head_b;
	// char	**str_arr;
	// char	**ptr_arr;
	current_flag = all->flag;
	// ft_printf("flag in b = %d\n", current_flag);
	all->max = all->mid;
	all->mid = calculate_mid_order(all, all->stack_b);
	// ft_printf("mid in b process %d\n", all->mid);
	// ft_printf("flag %d\n", all->flag);
	if (all->mid == 0)
		return ;
	str_arr = malloc(sizeof(char *) * (all->stack_b->size * 2 + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL);
	curr = all->stack_b->head;
	flag_nodes = count_flag_elements(all->stack_b, current_flag);
	// ft_printf("count_flag_elements result %d\n", flag_nodes);
	cmd_i = 0;
	all->flag++;
	while (flag_nodes > 0)
	{
		// ft_printf("count flag nodes %d in while loop\n", flag_nodes);
		curr = all->stack_b->head;
		// ft_printf("NEXT = [%d] MAX =%d MID =%d all.flag =%d curr = [%d] flag =%d next =%p\n",
		// 	all->next, all->max, all->mid, all->flag, curr->order, curr->flag,
		// 	curr->next);
		if (curr->order == all->next)
		{
			flag_nodes--;
			str_arr[cmd_i] = ft_strdup(push_a(all));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			check_strdup(all, str_arr, cmd_i);
			all->next++;
			all->stack_a->tail->flag = 0;
			cmd_i++;
		}
		else if (curr->flag == current_flag && curr->order >= all->mid)
		{
			str_arr[cmd_i] = ft_strdup(push_a(all));
			check_strdup(all, str_arr, cmd_i);
			all->stack_a->head->flag = all->flag;
			flag_nodes--;
			cmd_i++;
		}
		else if (curr->flag == current_flag && curr->order < all->mid)
		{
			str_arr[cmd_i] = ft_strdup(push_a(all));
			check_strdup(all, str_arr, cmd_i);
			all->stack_a->head->flag = all->flag;
			flag_nodes--;
			cmd_i++;
		}
		else
		{
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_b, 'b'));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
		}
		// fix if counter not fale counting
		flag_nodes = count_flag_elements(all->stack_b, current_flag);
	}
	str_arr[cmd_i] = NULL;
	ptr_arr = str_arr;
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr);
	// ft_printf("end process b\n");
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

int	stack_contains_next(t_llist *stack, int flag, int next)
{
	t_node	*ptr_head;

	ptr_head = stack->head;
	while (ptr_head && ptr_head->flag == flag)
	{
		if (ptr_head->order == next)
			return (1);
		ptr_head = ptr_head->next;
	}
	return (0);
}

int	sort_small(t_all *all, char name)
{
	t_llist	*stack;
	int		first;
	int		second;
	int		third;

	stack = all->stack_a;
	first = stack->head->order;
	second = stack->head->next->order;
	third = stack->head->next->next->order;
	// ft_printf("rest stack a %d\n", all->stack_a->size - all->next);
	if (all->stack_a->size - all->next == 2 && (first > second
			&& second > third))
	{
		ft_printf("%s", rotate(stack, name));
		ft_printf("%s", swap(stack, name));
		ft_printf("%s", push_b(all));
		ft_printf("%s", push_b(all));
		ft_printf("%s", reverse_rotate(stack, name));
		ft_printf("%s", push_a(all));
		ft_printf("%s", push_a(all));
		ft_printf("%s", rotate(stack, name));
		ft_printf("%s", rotate(stack, name));
		ft_printf("%s", rotate(stack, name));
	}
	else if (all->stack_a->size - all->next == 1)
	{
		ft_printf("%s", swap(stack, name));
		ft_printf("%s", rotate(stack, name));
		ft_printf("%s", rotate(stack, name));
	}
	else if (all->stack_a->size - all->next == 0)
		ft_printf("%s", rotate(stack, name));
	// else if (first > second && third < first)
	// 	ft_printf("%s", rotate(stack, name));
	// else if (first > second && third > first)
	// 	ft_printf("%s", swap(stack, name));
	// else if (first < second && first > third)
	// 	ft_printf("%s", reverse_rotate(stack, name));
	// else if (first < second && first < third)
	// {
	// 	ft_printf("%s", swap(stack, name));
	// 	ft_printf("%s", rotate(stack, name));
	// }
	return (0);
}

// ./push_swap 9 6 3 13 7 11 2 15 1 10 5 12 4 14 8
void	sort_big(t_all *all)
{
	t_node	*ptr_head_a;
	t_node	*ptr_head_b;
	int		i;
	int		size;

	size = all->stack_a->size;
	i = 0;
	// int i;
	// i = 0;
	// ft_printf("current next = %d, flag = %d\n", all->next, all->flag);
	while (all->next <= size)
	{
		ft_printf("current next = %d, flag = %d\n", all->next, all->flag);
		ft_printf("loop %d result = %d, flag = %d\n", i, all->next, all->flag);
		ptr_head_a = all->stack_a->head;
		while (ptr_head_a)
		{
			ft_printf("stack a before %d loop [%d] =%d flag =%d\n ", i,
				ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
			ptr_head_a = ptr_head_a->next;
		}
		ptr_head_b = all->stack_b->head;
		while (ptr_head_b)
		{
			ft_printf("stack b before %d loop [%d] = %d flag =%d\n ", i,
				ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
			ptr_head_b = ptr_head_b->next;
		}
		if (all->next == 1)
			first_process(all);
		if (count_flag_elements(all->stack_b, all->flag) > 0)
			process_b(all);
		ptr_head_a = all->stack_a->head;
		while (ptr_head_a)
		{
			ft_printf("stack a after ps B %d loop [%d] =%d flag =%d\n ", i,
				ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
			ptr_head_a = ptr_head_a->next;
		}
		ptr_head_b = all->stack_b->head;
		while (ptr_head_b)
		{
			ft_printf("stack b after ps B%d loop [%d] = %d flag =%d\n ", i,
				ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
			ptr_head_b = ptr_head_b->next;
		}
		if (count_flag_elements(all->stack_a, all->flag) != 0)
			process_a_flag(all);
		// ft_printf("size %d - all->next %d =  %d\n", size, all->next, size
		// 	- all->next);
		if (size - all->next > 3)
		{
			// ft_printf("before ps a2 size - all->next = %d\n", size - all->next);
			process_a2(all);
		}
		else if (count_flag_elements(all->stack_b, all->flag) == 0)
			{
				// ft_printf("small sort HEAD %d\n", all->stack_a->head->order);
				sort_small(all, 'a');
				break ;
		}
		i++;
	}
	ft_printf("size %d - all->next %d =  %d\n", size, all->next, size
			- all->next);
	// ptr_head_a = all->stack_a->head;
	// while (ptr_head_a)
	// {
	// 	ft_printf("stack a after %d loop [%d] =%d flag =%d\n ", i,
	// 		ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("stack b after %d loop [%d] = %d flag =%d\n ", i,
	// 		ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
	// 	ptr_head_b = ptr_head_b->next;
	// }
}
