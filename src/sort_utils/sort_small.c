/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:56:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/03 20:24:26 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_llist *stack_a)
{
	t_node	*min;
	t_node	*ptr_head;
	int		min_index;
	int		i;

	i = 0;
	min = stack_a->head;
	ptr_head = stack_a->head;
	// ft_printf("ptr_head = %d [%p]\n", ptr_head->value, ptr_head);
	while (ptr_head)
	{
		if (ptr_head->value < min->value)
		{
			min = ptr_head;
			min_index = i;
			// ft_printf("min = %d\n", ptr_head->value);
		}
		ptr_head = ptr_head->next;
		i++;
	}
	return (min_index);
}

void	shift_min_to_head(t_llist *stack_a)
{
	int	rra_times;
	int	min_index;

	rra_times = 0;
	min_index = get_min_index(stack_a);
	if (min_index == 0)
		return ;
	if (min_index <= stack_a->size / 2)
	{
		while (min_index-- > 0)
			ft_printf("%s\n", rotate(stack_a, 'a'));
	}
	else
	{
		rra_times = stack_a->size - min_index;
		while (rra_times-- > 0)
			ft_printf("%s\n", reverse_rotate(stack_a, 'a'));
	}
}

void	sort3(t_all *all)
{
	int		first;
	int		second;
	int		third;
	t_node	*ptr;

	ft_printf("start sort3\n");
	ptr = all->stack_a->head;
	ft_printf("head = %p\n", ptr);
	while (ptr)
	{
		ft_printf("stack_a [%d] = %d\n", ptr->order, ptr->value);
		ptr = ptr->next;
	}
	first = all->stack_a->head->order;
	second = all->stack_a->head->next->order;
	third = all->stack_a->head->next->next->order;
	if (first > second && second > third)
	{
		ft_printf("%s", swap(all->stack_a, 'a'));
		ft_printf("%s", reverse_rotate(all->stack_a, 'a'));
	}
	else if (first > second && third < first)
		ft_printf("%s", rotate(all->stack_a, 'a'));
	else if (first > second && third > first)
		ft_printf("%s", swap(all->stack_a, 'a'));
	else if (first < second && first > third)
		ft_printf("%s", reverse_rotate(all->stack_a, 'a'));
	else if (first < second && first < third)
	{
		ft_printf("%s", swap(all->stack_a, 'a'));
		ft_printf("%s", rotate(all->stack_a, 'a'));
	}
}

int *create_orders_arr(t_llist *stack)
{
	int *arr;
	t_node *ptr_head;
	int *ptr_arr;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	ptr_head = stack->head;
	ptr_arr = arr;
	while (ptr_head)
	{
		*arr++ = ptr_head->order;
		ptr_head = ptr_head->next;
	}
	return (ptr_arr);
}

void	sort4(t_all *all)
{
	int		*arr;
	t_node	*ptr;

	shift_min_to_head(all->stack_a);
	ptr = all->stack_a->head;
	ft_printf("head before sort 3 = %p\n", ptr);
	while (ptr)
	{
		ft_printf("stack_a [%d] = %d\n", ptr->order, ptr->value);
		ptr = ptr->next;
	}
	arr = create_orders_arr(all->stack_a);
	if (!arr)
	{
		free_all(all);
		return ;
	}
	ft_printf(" arr = %d\n", arr[0]);
	if (!is_sorted(arr, all->stack_a->size))
	{
		ft_printf("%s\n", push_b(all));
		ft_printf("size before sort3 = %d", all->stack_a->head);
		sort3(all);
		ft_printf("%s", push_a(all));
	}
	free(arr);
}
