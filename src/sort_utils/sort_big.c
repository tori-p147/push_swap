/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/07 22:04:49 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_chunks(t_llist *stack)
{
	t_node	*curr;
	int		total_count;
	int		num_chunks;
	int		chunk_size;

	total_count = stack->size;
	if (total_count <= 100)
		num_chunks = 5 + (total_count / 20);
	else if (total_count <= 500)
		num_chunks = 20 + (total_count / 50);
	else
		num_chunks = 50 + (total_count / 100);
	chunk_size = total_count / num_chunks;
	if (chunk_size == 0)
		chunk_size = 1;
	curr = stack->head;
	while (curr)
	{
		curr->chunk = curr->order / chunk_size;
		curr = curr->next;
	}
}

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

	// t_node	*ptr_head_b;
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
		str_arr = malloc(sizeof(char *) * (stack_b->size * 2 + 1));
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
				str_arr[cmd_i] = ft_strdup(push_a(all, all->stack_b->head));
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
				ft_printf("pushed next order = %d into a and rotated\n",
					curr_order);
				ft_printf("------\n");
			}
			else if (curr_order >= all->mid)
			{
				str_arr[cmd_i] = ft_strdup(push_a(all, all->stack_b->head));
				check_strdup(all, str_arr, cmd_i);
				// ptr_head_b = all->stack_b->head;
				// while (ptr_head_b)
				// {
				// 	ft_printf("stack b [%d] = %d next = %p\n",
				// 		ptr_head_b->order, ptr_head_b->value, ptr_head_b->next);
				// 	ptr_head_b = ptr_head_b->next;
				// }
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
	}
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
			str_arr[i] = ft_strdup(push_b(all, all->stack_a->head));
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

int	count_chunk(t_all *all)
{
	t_node	*ptr_head;
	int		count;

	count = 0;
	ptr_head = all->stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->chunk == all->chunk)
		{
			ft_printf("count order = [%d] chunk = %d\n", ptr_head->order, ptr_head->chunk);
			count++;
				}
		ptr_head = ptr_head->next;
	}
	ft_printf("----\n");
	return (count);
	// check chunk is empty
}

int	calculate_mid_in_chunk(t_all *all)
{
	int		mid;
	t_node	*ptr_head;
	int		*orders;
	int		count;
	int		i;
	t_array	chunk_nodes;

	count = 0;
	i = 0;
	count = count_chunk(all);
	ft_printf("count for mid = %d\n", count);
	if (count == 0)
		return (0);
	orders = malloc(sizeof(int) * count);
	if (!orders)
		return (-1);
	ptr_head = all->stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->chunk == all->chunk)
			orders[i++] = ptr_head->order;
		ptr_head = ptr_head->next;
	}
	chunk_nodes.ints = orders;
	chunk_nodes.length = count;
	sort(&chunk_nodes);
	mid = orders[count / 2];
	free(chunk_nodes.ints);
	ft_printf("mid for count %d = %d\n", count, mid);
	return (mid);
}

void	stack_a_chunk(t_all *all)
{
	t_node	*curr;
	t_node	*ptr_head_a;
	t_node	*ptr_head_b;
	int		cmd_i;
	char	**str_arr;
	char	**ptr_arr;
	int		loop_count;
	int count_chunks;

	// посчитать сколько есть нодов под текущим чанком
	// ft_printf("stack_a_chunk start: chunk=%d, count=%d\n", all->chunk,
	// 	count_chunk(all));
	// найти медиану
	all->mid = calculate_mid_in_chunk(all);
	// if chunk is empty return -> check next chunk
	if (all->mid == -1)
		exit_error_big_sort(all, NULL, 0);
	else if (all->mid == 0)
		return ;
	str_arr = malloc(sizeof(char *) * (all->stack_a->size * 2 + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL, 0);
	curr = all->stack_a->head;
	loop_count = all->stack_a->size;
	count_chunks = count_chunk(all);
	cmd_i = 0;
	while (count_chunks > 0 && loop_count-- > 0)
	{
		ft_printf("count in while loop %d\n", count_chunks);
		ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("stack a after chunk end [%d] = %d, chunk = (%d), next = %p\n",
			ptr_head_a->order, ptr_head_a->value, ptr_head_a->chunk,
			(void *)ptr_head_a->next);
		ptr_head_a = ptr_head_a->next;
	}
	// ptr_head_b = all->stack_b->head;
	// while (ptr_head_b)
	// {
	// 	ft_printf("stack b after chunk end [%d] = %d, chunk = (%d),next = %p\n",
	// 		ptr_head_b->order, ptr_head_b->value, ptr_head_b->chunk,
	// 		(void *)ptr_head_b->next);
	// 	ptr_head_b = ptr_head_b->next;
	// }

	ft_printf("curr = %p chunk = %d next = %p\n", curr, curr->chunk, curr->next);
		if (curr->chunk == all->chunk)
		{
			if (curr->order == all->next)
			{
				str_arr[cmd_i] = ft_strdup(push_a(all, curr));
				check_strdup(all, str_arr, cmd_i);
				cmd_i++;
				str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
				check_strdup(all, str_arr, cmd_i);
				all->next++;
				ptr_head_a = all->stack_a->head;
				all->stack_a->head->chunk = all->chunk;
				count_chunks--;
			}
			else if (curr->order >= all->mid)
				str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			else
			{
				str_arr[cmd_i] = ft_strdup(push_b(all, curr));
				count_chunks--;
				ptr_head_b = all->stack_b->head;
	while (ptr_head_b)
	{
		ft_printf("stack b after chunk end [%d] = %d, chunk = (%d),next = %p\n",
			ptr_head_b->order, ptr_head_b->value, ptr_head_b->chunk,
			(void *)ptr_head_b->next);
		ptr_head_b = ptr_head_b->next;
	}
			}
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			curr = curr->next;
			ft_printf("curr next order= [%d]\n", curr->next->order);
		}
		else
		{
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			curr = curr->next;
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
	ft_printf("stack_a_chunk end: chunk=%d, count=%d\n", all->chunk,
		count_chunk(all));
	ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("stack a after chunk end [%d] = %d, chunk = (%d), next = %p\n",
			ptr_head_a->order, ptr_head_a->value, ptr_head_a->chunk,
			(void *)ptr_head_a->next);
		ptr_head_a = ptr_head_a->next;
	}
	ptr_head_b = all->stack_b->head;
	while (ptr_head_b)
	{
		ft_printf("stack b after chunk end [%d] = %d, chunk = (%d),next = %p\n",
			ptr_head_b->order, ptr_head_b->value, ptr_head_b->chunk,
			(void *)ptr_head_b->next);
		ptr_head_b = ptr_head_b->next;
	}
}

int	calculate_mid(int max, int next)
{
	return ((max - next) / 2 + next);
}

int	has_chunk(t_all *all)
{
	t_node	*ptr_head;
	int		size;

	size = 0;
	ptr_head = all->stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->chunk == all->chunk)
			size++;
		ptr_head = ptr_head->next;
	}
	ft_printf("size in has chunk = %d\n", size);
	return (size);
}
// ./push_swap 9 6 3 13 7 11 2 15 1 10 5 12 4 14 8
void	sort_big(t_all *all)
{
	t_node	*ptr_head_a;
	t_node	*ptr_head_b;

	assign_chunks(all->stack_a);
	ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("stack a before [%d] = %d, chunk = (%d), next = %p\n",
			ptr_head_a->order, ptr_head_a->value, ptr_head_a->chunk,
			(void *)ptr_head_a->next);
		ptr_head_a = ptr_head_a->next;
	}
	ft_printf("next = %d\n", all->next);
	ft_printf("max = %d\n", all->max);
	ft_printf("mid = %d\n", all->mid);
	ft_printf("chunk = %d\n", all->chunk);
	push_half_to_b(all);
	push_a_or_rotate(all);
	ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("stack a after pa/ra [%d] = %d, chunk = (%d), next = %p\n",
			ptr_head_a->order, ptr_head_a->value, ptr_head_a->chunk,
			(void *)ptr_head_a->next);
		ptr_head_a = ptr_head_a->next;
	}
	ptr_head_b = all->stack_b->head;
	while (ptr_head_b)
	{
		ft_printf("stack b after pa/ra  [%d] = %d, chunk = (%d),next = %p\n",
			ptr_head_b->order, ptr_head_b->value, ptr_head_b->chunk,
			(void *)ptr_head_b->next);
		ptr_head_b = ptr_head_b->next;
	}
	ft_printf("current next = %d, max = %d\n", all->next, all->max);
	all->chunk++;
	// while (has_chunk(all))
	// {
	// 	if (count_chunk(all) > 0)
	// 	{
	// 		ft_printf("Checking chunk %d in stack A, has_chunk = %d\n",
	// 			all->chunk, has_chunk(all));
			stack_a_chunk(all);
			ptr_head_a = all->stack_a->head;
			all->chunk++;
			stack_a_chunk(all);
	// 	}
	// 	else
	// 	{
	// 		all->chunk++;
	// 		ft_printf("chunk updated = %d\n", all->chunk);
	// 	}
	// }
	// ft_printf("current next = %d, max = %d\n", all->next, all->max);
}
