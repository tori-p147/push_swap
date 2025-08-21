/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/21 22:50:01 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	first_process(t_all *all, t_cmd_list *cmd_list)
{
	int	size;
	int	curr_order;

	all->mid = all->max / 2 + all->next;
	size = all->stack_a->size;
	while (cmd_list->cmd_i < size)
	{
		curr_order = all->stack_a->head->order;
		if (curr_order <= all->mid)
		{
			do_push_b(all, cmd_list);
			all->stack_b->head->flag = all->flag + 1;
		}
		else
			do_rotate_a(all, cmd_list);
	}
	all->flag = 1;
}

int	find_max_flag(t_llist *stack)
{
	t_node	*tmp;
	int		max_flag;

	tmp = stack->head;
	max_flag = 0;
	while (tmp)
	{
		if (tmp->flag > max_flag)
		{
			max_flag = tmp->flag;
		}
		tmp = tmp->next;
	}
	return (max_flag);
}

void	process_a_flag(t_all *all, t_cmd_list *cmd_list)
{
	int	max_flag;

	// ft_printf("start a\n");
	max_flag = find_max_flag(all->stack_a);
	// ft_printf("loop %d result = %d, flag = %d\n", cmd_i, all->next,
	// ft_printf("current next = %d, max_flag = %d\n", all->next, max_flag);
	while (all->stack_a->head && all->stack_a->head->flag == max_flag)
	{
		if (all->stack_a->head->order == all->next)
		{
			do_rotate_a(all, cmd_list);
			all->next++;
			all->stack_a->tail->flag = -1;
			continue ;
		}
		do_push_b(all, cmd_list);
		if (max_flag == 0)
			all->stack_b->head->flag = all->flag;
		cmd_list->cmd_i++;
	}
	// ft_printf("end a\n");
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

int	calculate_mid_order_for_flag(t_llist *stack, int flag, int next)
{
	t_node	*curr;
	int		max;

	curr = stack->head;
	max = next;
	while (curr)
	{
		if (curr->flag == flag && curr->order > max)
			max = curr->order;
		curr = curr->next;
	}
	return ((max - next + 1) / 2 + next);
}

void	check_capacity(t_all *all, t_cmd_list *cmd_list)
{
	int		new_capacity;
	char	**new_arr;
	int		i;

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
		new_arr[i] = NULL;
		free(cmd_list->str_arr);
		cmd_list->str_arr = new_arr;
		cmd_list->capacity = new_capacity;
	}
}

int	get_max_index(t_llist *stack_b)
{
	t_node	*max;
	t_node	*ptr_head;
	int		max_order;
	int		i;

	i = 0;
	max = stack_b->head;
	max_order = 0;
	ptr_head = stack_b->head;
	while (ptr_head)
	{
		if (ptr_head->order > max->order)
		{
			max = ptr_head;
			max_order = i;
		}
		ptr_head = ptr_head->next;
		i++;
	}
	return (max_order);
}

void	move_to_top_b_rotate(t_all *all, t_cmd_list *cmd_list)
{
	t_node	*curr;
	int		next_pos;

	if (all->stack_b->size == 2)
	{
		if (all->stack_b->head->order > all->stack_b->tail->order)
			do_swap_b(all, cmd_list);
		return ;
	}
	curr = all->stack_b->head;
	next_pos = 0;
	while (curr)
	{
		if (curr->order == all->next)
			break ;
		next_pos++;
		curr = curr->next;
	}
	if (next_pos <= all->stack_b->size / 2)
		do_rotate_b(all, cmd_list);
}

void	move_to_top_b(t_all *all, t_cmd_list *cmd_list)
{
	t_node	*curr;
	int		next_pos;
	int size;

	size = all->stack_b->size;
	if (size == 2)
	{
		if (all->stack_b->head->order > all->stack_b->tail->order)
			do_swap_b(all, cmd_list);
		return ;
	}
	curr = all->stack_b->head;
	next_pos = 0;
	while (curr)
	{
		if (curr->order == all->next)
			break ;
		next_pos++;
		curr = curr->next;
	}
	if (next_pos == 0)
		return ;
	if (next_pos <= size / 1.5)
		do_rotate_b(all, cmd_list);
	else
		do_reverse_rotate_b(all, cmd_list);
}

int	is_next_found(t_llist *stack, int next)
{
	t_node	*ptr_head;

	ptr_head = stack->head;
	while (ptr_head)
	{
		if (ptr_head->order == next)
		{
			// ft_printf("next found\n");
			return (1);
		}
		ptr_head = ptr_head->next;
	}
	return (0);
}

void	process_b(t_all *all, t_cmd_list *cmd_list)
{
	t_node	*curr;
	int		current_flag;
	int		size;
	int		i;

	i = 0;
	all->flag = all->stack_b->head->flag;
	current_flag = all->flag;
	curr = NULL;
	// ft_printf("start b\n");
	// ft_printf("count_flag_elements result %d\n", flag_nodes);
	while (count_flag_elements(all->stack_b, current_flag) > 0)
	{
		all->mid = calculate_mid_order_for_flag(all->stack_b, current_flag,
				all->next);
		size = count_flag_elements(all->stack_b, current_flag);
		while (size-- > 0)
		{
			// all->mid = calculate_mid_order_for_flag(all->stack_b,
					// current_flag,
			// 		all->next);
			curr = all->stack_b->head;
			// ft_printf("NEXT = [%d] MAX =%d MID =%d all.flag =%d curr = [%d] flag =%d next =%p\n",
			// 	all->next, all->max, all->mid, all->flag, curr->order,
			// 	curr->flag, curr->next);
			if (curr->order == all->next && size > 0)
			{
				do_push_a(all, cmd_list);
				all->next++;
				if (is_next_found(all->stack_b, all->next))
					move_to_top_b(all, cmd_list);
				do_rotate_a(all, cmd_list);
				// if (is_next_found(all->stack_b, all->next))
				// 	move_to_top_b_rotate(all, cmd_list);
				all->stack_a->tail->flag = -1;
			}
			else if (curr->order >= all->mid)
			{
				do_push_a(all, cmd_list);
				all->stack_a->head->flag = all->flag + 1;
			}
			else if (is_next_found(all->stack_b, all->next))
				move_to_top_b(all, cmd_list);
			else
				process_a_flag(all, cmd_list);
		}
		if (count_flag_elements(all->stack_b, current_flag) == 0)
			current_flag++;
		i++;
	}
	all->flag = current_flag;
	// ft_printf("all->flag in b %d\n", all->flag);
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

int	stack_contains_next_with_0_flag(t_llist *stack, int next, int flag)
{
	t_node	*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (ptr->order == next && ptr->flag != flag)
		{
			// ft_printf("NEXT DETECTED %d\n", next);
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

// void	find_and_move_next(t_all *all)
// {
// 	t_node	*ptr;
// 	int		steps;

// 	ptr = all->stack_a->head;
// 	steps = 0;
// 	// Ищем позицию next в стеке A
// 	while (ptr && ptr->order != all->next)
// 	{
// 		ptr = ptr->next;
// 		steps++;
// 	}
// 	if (!ptr)
// 		return ; // next не найден (это ошибка)
// 	// Оптимально перемещаем next наверх
// 	if (steps <= all->stack_a->size / 2)
// 	{
// 		while (all->stack_a->head->order != all->next)
// 		{
// 			// ft_printf("MOVE rotate = [%d]\n", all->stack_a->head->order);
// 			ft_printf(rotate(all->stack_a, 'a'));
// 		}
// 	}
// 	else
// 	{
// 		while (all->stack_a->head->order != all->next)
// 		{
// 			// ft_printf("MOVE rr = [%d]\n", all->stack_a->head->order);
// 			ft_printf(reverse_rotate(all->stack_a, 'a'));
// 		}
// 	}
// 	// После перемещения:
// 	// ft_printf("MOVE NEXT = [%d]\n", all->stack_a->head->order);
// 	ft_printf(rotate(all->stack_a, 'a'));
// 	all->stack_a->tail->flag = 0; // Помечаем как отсортированный
// 	all->next++;
// }

// void	sort3_last(t_llist *stack, char name)
// {
// 	int	first;
// 	int	second;
// 	int	third;

// 	first = stack->head->order;
// 	second = stack->head->next->order;
// 	third = stack->head->next->next->order;
// 	if (first > second && second > third)
// 	{
// 		ft_printf("%s", swap(stack, name));
// 		ft_printf("%s", reverse_rotate(stack, name));
// 	}
// 	else if (first > second && third < first)
// 		ft_printf("%s", rotate(stack, name));
// 	else if (first > second && third > first)
// 		ft_printf("%s", swap(stack, name));
// 	else if (first < second && first > third)
// 		ft_printf("%s", reverse_rotate(stack, name));
// 	else if (first < second && first < third)
// 	{
// 		// only this case rewrited last: [18, 20, 19]
// 		ft_printf("%s", rotate(stack, name));
// 		ft_printf("%s", swap(stack, name));
// 		while (stack->head->order != 1)
// 			ft_printf("%s", rotate(stack, name));
// 	}
// }

// int	sort_small(t_all *all, char name)
// {
// 	t_llist	*stack;

// 	stack = all->stack_b;
// 	// ft_printf("rest stack b %d\n", all->stack_b->size);
// 	if (all->stack_b->size == 2)
// 		ft_printf("%s", rotate(stack, name));
// 	else if (all->stack_b->size == 3)
// 		ft_printf("%s", swap(stack, name));
// 	else
// 		sort3_last(all->stack_b, 'b');
// 	return (0);
// }

int	is_sorted_stack(t_llist *stack)
{
	t_node	*ptr_head;
	int		curr_order;

	ptr_head = stack->head;
	while (ptr_head->next)
	{
		curr_order = ptr_head->order;
		if (curr_order > ptr_head->next->order)
			return (0);
		ptr_head = ptr_head->next;
	}
	return (1);
}

void	print_state(t_all *all, char *msg, int i)
{
	t_node	*ptr_head_a;
	t_node	*ptr_head_b;

	ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("a %s %d loop [%d] =%d flag =%d\n ", msg, i,
			ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
		ptr_head_a = ptr_head_a->next;
	}
	ptr_head_b = all->stack_b->head;
	while (ptr_head_b)
	{
		ft_printf("b %s %d loop [%d] = %d flag =%d\n ", msg, i,
			ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
		ptr_head_b = ptr_head_b->next;
	}
}

int	get_min_count(int pb_count, int pa_count)
{
	if (pa_count > pb_count)
		return (pb_count);
	else
		return (pa_count);
}

//./push_swap 30 97 4 8 13 26 90 73 34 36 38 79 46 28 2 100 52 89 35 99 39 63 54 41 31 65 70 51 77 27 59 85 96 66 58 24 14 67 61 80 45 5 55 23 17 74 18 50 72 37 9 15 98 20 33 91 84 93 62 3 82 78 42 69 16 92 64 95 94 68 10 7 22 1 60 6 75 81 86 76 71 25 12 57 44 83 56 43 32 19 11 29 87 48 49 88 21 53 40 47
// ./push_swap 2 9 1 20 12 14 5 7 16 11 6 3 10 13 17 18 19 4 8 15
void	sort_big(t_all *all, t_cmd_list *cmd_list)
{
	int			i;

	i = 0;
	first_process(all, cmd_list);
	// print_state(all, "stack after first ", i);
	while (!is_sorted_stack(all->stack_a) || all->stack_b->size > 0)
	{
		// if (all->stack_b->size == 3 || all->stack_b->size == 2)
		// {
		// 	// ft_printf("small sort HEAD %d\n", all->stack_a->head->order);
		// 	sort_small(all, 'a');
		// 	// print_state(all, "stack after small sort ", i);
		// 	// break ;
		// }
		if (all->stack_b->size > 0)
		{
			// ft_printf("current next = %d, flag = %d\n", all->next,
			// all->flag);
			process_b(all, cmd_list);
			// print_state(all, "stack after b", i);
			// ft_printf("b size = %d\n", all->stack_b->size);
		}
		if (all->stack_b->size == 0)
		{
			// ft_printf("current next = %d, flag = %d\n", all->next,
			// all->flag);
			process_a_flag(all, cmd_list);
			// print_state(all, "stack after a flag", i);
		}
		i++;
		// ft_printf("current next = %d, flag = %d\n", all->next, all->flag);
		// 	process_b(all);
	}
	cmd_list->str_arr[cmd_list->cmd_i] = NULL;
	// ptr_arr = cmd_list.str_arr;
	// while (*ptr_arr)
	// {
	// 	ft_printf("%s", *ptr_arr);
	// 	ptr_arr++;
	// }
	// ft_printf("cmds befre = %d\n", cmd_list.cmd_i);
	// combine_cmd_list(&cmd_list);
	// ptr_arr = cmd_list.str_arr;
	// while (*ptr_arr)
	// {
	// 	ft_printf("%s", *ptr_arr);
	// 	ptr_arr++;
	// }
	// ft_printf("cmds aft = %d\n", cmd_list.cmd_i);
	print_state(all, "stack after a flag", i);
}
