/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lincked_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:15:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/06 16:13:17 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, int order, int chunk)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->order = order;
	new_node->chunk = chunk;
	new_node->next = NULL;
	new_node->prev = NULL;
	// printf("new node %d created\n", new_node->value);
	return (new_node);
}

t_node	*remove_first(t_llist *list)
{
	t_node	*first;
	t_node	*second;

	if (!list)
		return (NULL);
	first = list->head;
	if (list->size > 1)
	{
		second = first->next;
		list->head = second;
		second->prev = NULL;
	}
	else
	{
		list->head = NULL;
		list->tail = NULL;
	}
	first->prev = NULL;
	first->next = NULL;
	list->size--;
	// ft_printf("remove_front end\n");
	return (first);
}

void	add_front(t_llist *list, t_node *new_node)
{
	t_node	*second;

	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = new_node;
		list->size++;
		return ;
	}
	second = list->head;
	list->head = new_node;
	list->head->prev = NULL;
	list->head->next = second;
	second->prev = new_node;
	list->size++;
}

void	add_last(t_llist *list, t_node *new_node)
{
	t_node	*ptr_tail;

	ptr_tail = list->tail;
	ptr_tail->next = new_node;
	list->tail = new_node;
	new_node->prev = ptr_tail;
	list->size++;
}

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

void	add_node(t_llist *list, t_node *new_node)
{
	if (list->size == 0)
		add_front(list, new_node);
	else
		add_last(list, new_node);
}

t_all	*init_all(t_all *all, t_llist *list_a, t_llist *list_b)
{
	all = malloc(sizeof(t_all));
	if (!all)
		exit_create_list_error(NULL, list_a, list_b, NULL);
	all->stack_a = list_a;
	all->stack_b = list_b;
	all->next = 0;
	all->max = get_max_order(list_a);
	all->mid = calculate_mid(all->max, all->next);
	all->chunk = 0;
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
				new_node = create_node(unsorted->ints[i], j, 0);
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
	if (!list)
		exit_create_list_error(NULL, list, NULL, NULL);
	return (list);
}

t_all	*create_all(t_all *all, t_llist *list, t_array *ints)
{
	t_llist	*stack_b;

	list = create_list(list, ints);
	stack_b = NULL;
	stack_b = init_list(stack_b);
	if (!stack_b)
		exit_create_list_error(NULL, list, NULL, NULL);
	all = NULL;
	all = init_all(all, list, stack_b);
	return (all);
}
