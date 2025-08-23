/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lincked_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:15:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:18:43 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*init_list(t_llist *list)
{
	list = malloc(sizeof(t_llist));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

t_all	*init_all(t_all *all, t_llist *list_a, t_llist *list_b)
{
	all = malloc(sizeof(t_all));
	if (!all)
		exit_create_list_error(NULL, list_a, list_b, NULL);
	all->stack_a = list_a;
	all->stack_b = list_b;
	all->next = 1;
	all->mid = 0;
	all->flag = 0;
	all->max = list_a->size;
	return (all);
}

t_llist	*fill_list(t_llist *list, t_array *unsorted, t_array *sorted)
{
	t_node	*new_node;
	int		i;
	int		j;

	i = 0;
	while (i < unsorted->length)
	{
		j = 0;
		while (j < sorted->length)
		{
			if (unsorted->ints[i] == sorted->ints[j])
			{
				new_node = create_node(unsorted->ints[i], j);
				if (!new_node)
					exit_create_list_error(NULL, list, NULL, unsorted);
				add_node(list, new_node);
				break ;
			}
			j++;
		}
		i++;
	}
	return (list);
}

t_llist	*create_list(t_llist *list, t_array *ints)
{
	t_array	sorted;
	t_array	unsorted;
	int		i;

	i = 0;
	list = init_list(list);
	if (!list)
		exit_create_list_error(NULL, NULL, NULL, ints);
	unsorted.ints = malloc(sizeof(int *) * ints->length);
	if (!unsorted.ints)
		exit_create_list_error(NULL, list, NULL, ints);
	unsorted.length = ints->length;
	while (i < unsorted.length)
	{
		unsorted.ints[i] = ints->ints[i];
		i++;
	}
	sort(ints);
	sorted.ints = ints->ints;
	sorted.length = ints->length;
	list = fill_list(list, &unsorted, &sorted);
	free(unsorted.ints);
	free(ints->ints);
	return (list);
}

t_all	*create_all(t_all *all, t_llist *list, t_array *ints)
{
	t_llist	*stack_b;

	list = create_list(list, ints);
	if (!list)
		exit_create_list_error(NULL, list, NULL, NULL);
	stack_b = NULL;
	stack_b = init_list(stack_b);
	if (!stack_b)
		exit_create_list_error(NULL, list, NULL, NULL);
	all = NULL;
	all = init_all(all, list, stack_b);
	return (all);
}
