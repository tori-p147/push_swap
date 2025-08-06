/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/06 19:00:44 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_max_order(t_llist *stack_a)
{
	int		max_order;
	int		curr_order;
	t_node	*ptr_head;

	max_order = stack_a->head->order;
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		curr_order = ptr_head->order;
		if (curr_order > max_order)
			max_order = curr_order;
		ptr_head = ptr_head->next;
	}
	ft_printf("max order = %d\n", max_order);
	return (max_order);
}

void	check_strdup(t_all *all, char **str_arr, int cmd_i)
{
	if (!str_arr[cmd_i])
		exit_error_big_sort(all, str_arr, cmd_i);
}

void	push_a_or_rotate(t_all *all)
{
	char	**str_arr;
	char	**ptr_arr;
	t_llist	*stack_b;
	int		curr_order;
	int		i;
	int		size;
	int		cmd_i;
	t_node	*ptr_head_b;

	stack_b = all->stack_b;
	while (stack_b->size > 0)
	{
		cmd_i = 0;
		all->max = get_max_order(all->stack_b);
		ft_printf("next = %d\n", all->next);
		ft_printf("max = %d\n", all->max);
		if (all->max < all->next)
			return ;
		all->mid = calculate_mid(all->max, all->next);
		ft_printf("mid = %d\n", all->mid);
		ft_printf("chunk = %d\n", all->chunk);
		size = stack_b->size;
		ft_printf("size = %d\n", all->mid);
		str_arr = malloc(sizeof(char *) * (stack_b->size + 1));
		if (!str_arr)
			exit_error_big_sort(all, NULL, 0);
		i = 0;
		while (i < size)
		{
			curr_order = stack_b->head->order;
			ft_printf("curr order = [%d]\n", curr_order);
			ft_printf("next = [%d]\n", all->next);
			if (curr_order == all->next)
			{
				ft_printf("find order %d = next %d \n", curr_order, all->next);
				str_arr[cmd_i] = ft_strdup(push_a(all));
				check_strdup(all, str_arr, cmd_i);
				cmd_i++;
				str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
				// ptr_head_b = all->stack_b->head;
				// while (ptr_head_b)
				// {
				// 	ft_printf("stack b [%d] = %d next = %p\n",
				// 		ptr_head_b->order, ptr_head_b->value, ptr_head_b->next);
				// 	ptr_head_b = ptr_head_b->next;
				// }
				check_strdup(all, str_arr, cmd_i);
				all->next++;
				ft_printf("NEW next = [%d]\n", all->next);
				ft_printf("------\n");
			}
			else if (curr_order >= all->mid)
			{
				str_arr[cmd_i] = ft_strdup(push_a(all));
				check_strdup(all, str_arr, cmd_i);
				if (all->chunk == 0)
					all->stack_a->head->chunk = 1;
				ptr_head_b = all->stack_b->head;
				while (ptr_head_b)
				{
					ft_printf("stack b [%d] = %d next = %p\n",
						ptr_head_b->order, ptr_head_b->value, ptr_head_b->next);
					ptr_head_b = ptr_head_b->next;
				}
				ft_printf("------\n");
			}
			else
			{
				str_arr[cmd_i] = ft_strdup(rotate(stack_b, 'b'));
				check_strdup(all, str_arr, cmd_i);
				ft_printf("------\n");
			}
			cmd_i++;
			i++;
		}
		str_arr[cmd_i] = NULL;
		ptr_arr = str_arr;
		while (*str_arr)
		{
			ft_printf("%s", *str_arr);
			str_arr++;
		}
		free_strs(ptr_arr, cmd_i);
		ft_printf("B SIZE BEFORE NEW LOOP = %d\n", stack_b->size);
	}
	all->chunk++;
	ft_printf("chunk = %d\n", all->chunk);
}

void	push_half_to_b(t_all *all)
{
	char	**str_arr;
	t_llist	*stack;
	int		curr_order;
	int		i;
	int		size;
	char	**ptr_arr;

	i = 0;
	stack = all->stack_a;
	size = stack->size;
	str_arr = malloc(sizeof(char *) * (stack->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL, 0);
	while (i < size)
	{
		curr_order = stack->head->order;
		ft_printf("curr = %d\n", curr_order);
		if (curr_order <= all->mid)
			str_arr[i] = ft_strdup(push_b(all));
		else
			str_arr[i] = ft_strdup(rotate(stack, 'a'));
		check_strdup(all, str_arr, i);
		i++;
	}
	str_arr[i] = NULL;
	ptr_arr = str_arr;
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr, i);
}

// int	is_sorted_stack(t_llist *stack_a)
// {
// 	t_node	*ptr;
// 	int		next_order;
// 	int		curr_order;

// 	ptr = stack_a->head;
// 	while (ptr)
// 	{
// 		curr_order = ptr->order;
// 		next_order = ptr->next->order;
// 		if (curr_order > next_order)
// 			return (0);
// 		ptr = ptr->next;
// 	}
// 	return (1);
// }

int count_chunk()
{
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->chunk == chunk)
			count++;
		ptr_head = ptr_head->chunk;
	}
	if (count == 0)
		return (-1);
		//check chunk is empty
}

int calculate_mid_in_chunk(t_llist *stack_a, int chunk)
{
	int mid;
	t_node *ptr_head;
	int *orders;
	int *size;
	int count;
	int i;
	t_array chunk_nodes;
	
	count = 0;
	i = 0;
	
	orders = malloc(sizeof(int) * count);
	if (!orders)
		return (-1);// ERROR exit
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->chunk == chunk)
			orders[i++] = ptr_head->order;
		ptr_head = ptr_head->chunk;
	}
	chunk_nodes.ints = orders;
	chunk_nodes.length = count;
	sort(&chunk_nodes);
	mid = orders[count / 2];
	free(chunk_nodes.ints);
	return (mid);
}

void	stack_a_chunk(t_all *all, int chunk, int size)
{
	t_node	*curr;
	int		cmd_i;
	char	**str_arr;
	char	**ptr_arr;
	int		i;

	cmd_i = 0;
	all->mid = calculate_mid_in_chunk(all->stack_a, all->chunk);
	// if chunk is empty return -> check next chunk
	if (all->mid == -1)
		exit_error_big_sort(all, NULL, 0);
	curr = all->stack_a->head;
	str_arr = malloc(sizeof(char *) * (all->stack_a->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL, 0);
	// refactor to chunk elements (not all)
	i = 0;
	while (i < size)
	{
		if (curr->chunk == chunk)
		{
			if (curr->order == all->next)
			{
				str_arr[cmd_i] = ft_strdup(push_a(all));
				check_strdup(all, str_arr, cmd_i);
				cmd_i++;
				str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
				check_strdup(all, str_arr, cmd_i);
				all->next++;
			}
			else if (curr->order >= all->mid)
				str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			else
				str_arr[cmd_i] = ft_strdup(push_b(all));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			i++;
		}
		else
		{
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			check_strdup(all, str_arr, cmd_i);
			i++;
			continue ;
		}
	}
	str_arr[cmd_i] = NULL;
	ptr_arr = str_arr;
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr, cmd_i);
}

int	calculate_mid(int max, int next, int chunk)
{
	return ((max - next) / 2 + next);
}

int has_chunk(t_llist *stack_a, int chunk, int *size)
{
	t_node *ptr_head;

	*size = 0;
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->chunk == chunk)
			(*size)++;
		ptr_head = ptr_head->next;
	}
	ft_printf("size in has chunk = %d\n", *size);
	if (*size != 0)
		return (1);
	return (0);
}

void	sort_big(t_all *all)
{
	int	size;

	// t_node	*ptr_head_a;
	// t_node	*ptr_head_b;
	ft_printf("next = %d\n", all->next);
	ft_printf("max = %d\n", all->max);
	ft_printf("mid = %d\n", all->mid);
	ft_printf("chunk = %d\n", all->chunk);
	push_half_to_b(all);
	push_a_or_rotate(all);
	size = 0;
	ft_printf("chunk = %d\n", all->chunk);
	ft_printf("current next = %d, max = %d\n", all->next, all->max);
	while (has_chunk(all->stack_a, all->chunk, &size))
	{
		ft_printf("size = %d\n", size);
		stack_a_chunk(all, all->chunk, size);
		push_a_or_rotate(all);
	}
	ft_printf("current next = %d, max = %d\n", all->next, all->max);
	// ptr_head_a = all->stack_a->head;
	// while (ptr_head_a)
	// {
	// 	ft_printf("main stack a after [%d] = %d next = %p\n", ptr_head_a->order,
	// 		ptr_head_a->value, ptr_head_a->next);
	// 	ptr_head_a = ptr_head_a->next;
	// }
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("main stack b after [%d] = %d next = %p\n", ptr_head_b->order,
	// 		ptr_head_b->value, ptr_head_b->next);
	// 	ptr_head_b = ptr_head_b->next;
	// }
}
