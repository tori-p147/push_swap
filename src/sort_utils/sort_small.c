/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:56:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/04 17:01:47 by vmatsuda         ###   ########.fr       */
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
	min_index = 0;
	ptr_head = stack_a->head;
	while (ptr_head)
	{
		if (ptr_head->value < min->value)
		{
			min = ptr_head;
			min_index = i;
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

int	*create_orders_arr(t_llist *stack)
{
	int		*arr;
	t_node	*ptr_head;
	int		*ptr_arr;

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
	shift_min_to_head(all->stack_a);
	sort_rest(all, 3);
}

void	sort_rest(t_all *all, int unsort_nums_amount)
{
	int	*arr;

	arr = create_orders_arr(all->stack_a);
	if (!arr)
	{
		free_all(all);
		return ;
	}
	if (!is_sorted(arr, all->stack_a->size))
	{
		ft_printf("%s\n", push_b(all));
		if (unsort_nums_amount == 3)
			sort3(all);
		else if (unsort_nums_amount == 4)
			sort4(all);
		ft_printf("%s", push_a(all));
	}
	free(arr);
}

void	sort5(t_all *all)
{
	shift_min_to_head(all->stack_a);
	sort_rest(all, 4);
}
