/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/05 18:45:14 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*get_max_node(t_llist *stack_a)
{
	t_node	*max_node;
	t_node	*ptr_head;

	max_node = stack_a->head;
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->order > max_node->order)
			max_node = ptr_head;
		ptr_head = ptr_head->next;
	}
	ft_printf("max = %p,order = %d\n", max_node, max_node->order);
	return (max_node);
}

void	check_strdup(t_all *all, char **str_arr, int cmd_i)
{
	if (!str_arr[cmd_i])
		exit_error_big_sort(all, str_arr, cmd_i);
}

void	rotate_a_if_next_found(t_all *all, int *next_order, char **str_arr,
		int *cmd_i)
{
	t_node	*head;

	while ((head = all->stack_a->head) && head->order == *next_order)
	{
		str_arr[*cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
		check_strdup(all, str_arr, *cmd_i);
		(*cmd_i)++;
		(*next_order)++;
	}
}

int	push_to_a_if_found_next_order(t_all *all, int *next_order, char **str_arr,
		int cmd_i)
{
	t_node	*ptr_head;
	int		old_cmd;

	old_cmd = cmd_i;
	ptr_head = all->stack_b->head;
	str_arr[cmd_i] = ft_strdup(push_a(all));
	check_strdup(all, str_arr, cmd_i);
	cmd_i++;
	if (ptr_head->order != *next_order)
		ptr_head->flag = all->flag;
	rotate_a_if_next_found(all, next_order, str_arr, &cmd_i);
	return (cmd_i - old_cmd);
}

void	push_bigger_than_mid(t_all *all, char stack_name, int *next)
{
	char	**str_arr;
	char	**ptr_arr;
	t_llist	*stack;
	t_node	*curr;
	int		i;
	int		size;
	int		cmd_i;

	cmd_i = 0;
	i = 0;
	if (stack_name == 'a')
		stack = all->stack_a;
	else
		stack = all->stack_b;
	size = stack->size;
	str_arr = malloc(sizeof(char *) * (stack->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL, 0);
	while (i < size)
	{
		curr = stack->head;
		ft_printf("curr = %d\n", curr->order);
		// duplicate fix
		if (curr->order == *next)
		{
			str_arr[cmd_i] = ft_strdup(push_a(all));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			str_arr[cmd_i] = ft_strdup(rotate(all->stack_a, 'a'));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
			(*next)++;
		}
		else if (curr->order > all->mid)
		{
			curr->flag = all->flag;
			if (stack_name == 'b')
				cmd_i += push_to_a_if_found_next_order(all, next, str_arr,
						cmd_i);
			else
			{
				str_arr[cmd_i] = ft_strdup(push_b(all));
				check_strdup(all, str_arr, cmd_i);
				cmd_i++;
			}
		}
		else
		{
			if (stack_name == 'a')
				str_arr[cmd_i] = ft_strdup(rotate(stack, 'a'));
			else
				str_arr[cmd_i] = ft_strdup(rotate(stack, 'b'));
			check_strdup(all, str_arr, cmd_i);
			cmd_i++;
		}
		i++;
	}
	ft_printf("head a  = %d\n", stack->head->order);
	str_arr[cmd_i] = NULL;
	ptr_arr = str_arr;
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr, cmd_i);
}

void	push_smaller_than_mid(t_all *all, char stack_name)
{
	char	**str_arr;
	t_llist	*stack;
	t_node	*curr;
	int		i;
	int		size;
	char	**ptr_arr;

	i = 0;
	if (stack_name == 'a')
		stack = all->stack_a;
	else
		stack = all->stack_b;
	size = stack->size;
	str_arr = malloc(sizeof(char *) * (stack->size + 1));
	if (!str_arr)
		exit_error_big_sort(all, NULL, 0);
	while (i < size)
	{
		curr = stack->head;
		ft_printf("curr = %d\n", curr->order);
		if (curr->order <= all->mid)
		{
			if (stack_name == 'a')
				str_arr[i] = ft_strdup(push_b(all));
			else
				str_arr[i] = ft_strdup(push_a(all));
		}
		else
		{
			if (stack_name == 'a')
				str_arr[i] = ft_strdup(rotate(stack, 'a'));
			else
				str_arr[i] = ft_strdup(rotate(stack, 'b'));
		}
		check_strdup(all, str_arr, i);
		i++;
	}
	ft_printf("head a  = %d\n", stack->head->order);
	str_arr[i] = NULL;
	ptr_arr = str_arr;
	//./push_swap 9 6 3 13 7 11 2 15 1 10 5 12 4 14 8
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr, i);
}

void	sort_big(t_all *all)
{
	t_node	*max_node;
	int		next;
	t_node	*ptr_head_a;
	t_node	*ptr_head_b;

	max_node = get_max_node(all->stack_a);
	next = 1;
	all->max = max_node->order;
	ft_printf("max next order = %d\n", next);
	all->mid = (all->max + next) / 2;
	ft_printf("mid = %d\n", all->mid);
	push_smaller_than_mid(all, 'a');
	ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("main stack a after [%d] = %d next = %p\n", ptr_head_a->order,
			ptr_head_a->order, ptr_head_a->next);
		ptr_head_a = ptr_head_a->next;
	}
	ptr_head_b = all->stack_b->head;
	while (ptr_head_b)
	{
		ft_printf("main stack b after [%d] = %d next = %p\n", ptr_head_b->order,
			ptr_head_b->order, ptr_head_b->next);
		ptr_head_b = ptr_head_b->next;
	}
	max_node = get_max_node(all->stack_b);
	all->max = max_node->order;
	ft_printf("next 2 = %d\n", next);
	ft_printf("max 2 = %d\n", all->max);
	all->mid = (all->max + next) / 2;
	ft_printf("mid 2 = %d\n", all->mid);
	push_bigger_than_mid(all, 'b', &next);
	ft_printf("NEXT = %d\n", next);
}
