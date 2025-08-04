/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:22:36 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/04 18:18:05 by vmatsuda         ###   ########.fr       */
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
		if (ptr_head->value > max_node->value)
			max_node = ptr_head;
		ptr_head = ptr_head->next;
	}
	ft_printf("max = %p,value = %d\n", max_node, max_node->value);
	return (max_node);
}

void	sort_big(t_all *all)
{
	char	**str_arr;
	char	**ptr_arr;
	t_node	*max_node;
	t_node	*next_node;
	int		i;
	t_node	*curr;

	i = 0;
	str_arr = NULL;
	max_node = get_max_node(all->stack_a);
	all->max_order = max_node->order;
	if (max_node->next)
		next_node = max_node->next;
	else
		next_node = all->stack_a->head;
	all->med = all->max_order / 2 + next_node->order;
	ft_printf("med = %d\n", all->med);
	str_arr = malloc(sizeof(char *) * all->med);
	if (!str_arr)
		exit_error_big_sort(all, NULL);
	while (all->stack_a->head)
	{
		curr = all->stack_a->head;
		ft_printf("before: i = %d\n", i);
		if (curr->order < all->med)
		{
			str_arr[i] = ft_strdup(push_b(all));
			if (!str_arr[i])
				exit_error_big_sort(all, str_arr);
		}
		else
		{
			str_arr[i] = ft_strdup(rotate(all->stack_a, 'a'));
			if (!str_arr[i])
				exit_error_big_sort(all, str_arr);
		}
		i++;
		ft_printf("after: i = %d\n", i);
	}
	str_arr[i] = NULL;
	ptr_arr = str_arr;
	while (*str_arr)
	{
		ft_printf("%s", *str_arr);
		str_arr++;
	}
	free_strs(ptr_arr);
}
