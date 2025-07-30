/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lincked_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:15:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/30 17:49:39 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, int order, int flag)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->order = order;
	new_node->flag = flag;
	new_node->next = NULL;
	new_node->prev = NULL;
	printf("new node %d created\n", new_node->value);
	return (new_node);
}

t_node	*remove_front(t_llist *list)
{
	t_node	*tmp;
	t_node	*ptr_head;

	if (!list)
		return (NULL);
	ptr_head = list->head;
	if (list->size > 1)
	{
		tmp = ptr_head;
		ptr_head = ptr_head->next;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

void	add_front(t_llist *list, t_node *new_node)
{
	t_node	*ptr_head;

	printf("list p = %p\n", list);
	printf("list.size = %d\n", list->size);
	if (list->size == 0)
	{
		list->head = new_node;
		list->tail = new_node;
		printf("added first node = %d, order = %d\n", new_node->value,
			new_node->order);
		list->size++;
		return ;
	}
	ptr_head = list->head;
	list->head = new_node;
	list->tail = ptr_head;
	new_node->next = ptr_head;
	ptr_head->prev = new_node;
	printf("front added node = %d, order = %d\n", new_node->value,
		new_node->order);
}

void	add_back(t_llist *list, t_node *new_node)
{
	t_node	*ptr_tail;

	ptr_tail = list->tail;
	ptr_tail->next = new_node;
	list->tail = new_node;
	new_node->prev = ptr_tail;
	list->size++;
	printf("back added node = %d, order = %d\n", new_node->value,
		new_node->order);
}

t_llist	*init_list(t_llist *list)
{
	list = malloc(sizeof(t_llist));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	printf("init list success\n");
	return (list);
}

void	add_node(t_llist *list, t_node *new_node)
{
	if (list->size == 0)
		add_front(list, new_node);
	else
		add_back(list, new_node);
}

t_all	*init_all(t_all *all, t_llist *list_a, t_llist *list_b)
{
	all = malloc(sizeof(t_all));
	if (!all)
	{
		free_list(list_a);
		free_list(list_b);
		return (NULL);
	}
	all->stack_a = list_a;
	printf("all->stack_a p =%p\n", all->stack_a);
	all->stack_b = list_b;
	all->min_a = 0;
	all->med = 0;
	printf("init all success\n");
	return (all);
}

t_llist	*fill_list(t_llist *list, t_array *unsorted, t_array *sorted)
{
	t_node	*new_node;
	int		i;
	int		j;

	i = 0;
	printf("%d\n", unsorted->length);
	printf("%d\n", sorted->length);
	while (i < unsorted->length)
	{
		printf("i = %d\n", i);
		j = 0;
		while (j < sorted->length)
		{
			printf("j = %d\n", j);
			if (unsorted->ints[i] == sorted->ints[j])
			{
				printf("uns[%d] = %d, sort[%d] = %d\n", i, unsorted->ints[i], j,
					sorted->ints[j]);
				new_node = create_node(unsorted->ints[i], j, 0);
				if (!new_node)
				{
					free(unsorted->ints);
					free_list(list);
					return (NULL);
				}
				add_node(list, new_node);
				printf("new_node = %d\n", new_node->value);
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

	list = init_list(list);
	// printf("%p\n", list);
	if (!list)
		return (NULL);
	printf("list created%p\n", list);
	// printf("%p\n", list->head);
	// for (int j = 0; j < ints->length; j++)
	// 	ft_printf("%d\n", ints->ints[j]);
	unsorted.ints = malloc(sizeof(int *) * ints->length);
	if (!unsorted.ints)
	{
		printf("try free list %p\n", list);
		free_list(list);
		return (NULL);
	}
	unsorted.length = ints->length;
	for (int j = 0; j < unsorted.length; j++)
	{
		unsorted.ints[j] = ints->ints[j];
		ft_printf("unsorted.ints[%d] = %d\n", j, unsorted.ints[j]);
	}
	sort(ints);
	sorted.ints = ints->ints;
	sorted.length = ints->length;
	list = fill_list(list, &unsorted, &sorted);
	// printf("unsorted.ints before free%p\n", unsorted.ints);
	free(unsorted.ints);
	if (!list)
		return (NULL);
	return (list);
}

t_all	*create_all(t_all *all, t_llist *list, t_array *ints)
{
	t_llist	*stack_b;

	// t_llist	*stack_a;
	// stack_a = NULL;
	list = create_list(list, ints);
	if (!list)
		return (NULL);
	printf("created stack a %p\n", list);
	stack_b = NULL;
	stack_b = init_list(stack_b);
	if (!stack_b)
	{
		free_list(list);
		return (NULL);
	}
	printf("created stack b %p\n", stack_b);
	all = NULL;
	all = init_all(all, list, stack_b);
	if (!all)
		return (NULL);
	printf("created ALL %p\n", all);
	return (all);
}
