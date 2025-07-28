/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lincked_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:15:57 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 21:52:08 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	create_node(int value, int order, int flag)
{
	t_node	new_node;

	new_node.value = value;
	new_node.order = order;
	new_node.flag = flag;
	return (new_node);
}

void	add_first(t_llist *list, t_node *new_node)
{
	t_node	*ptr_head;

	if (!list)
	{
		list->head = new_node;
		printf("added first node = %d, order = %d\n", new_node->value, new_node->order);
		list->size++;
		return ;
	}
	ptr_head = list->head;
	list->head = new_node;
	new_node->next = ptr_head;
	ptr_head->prev = new_node;
}

void	add_last(t_llist *list, t_node *new_node)
{
	t_node	*ptr_tail;

	if (!list)
	{
		list->head = new_node;
		printf("added last node = %d, order = %d\n", new_node->value, new_node->order);
		list->size++;
		return ;
	}
	ptr_tail = list->tail;
	list->tail = new_node;
	new_node->prev = ptr_tail;
	ptr_tail->next = new_node;
}
void init_list(t_llist *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

t_llist	create_list(t_llist *list, t_array *ints)
{
	t_node new_node;
	int i;
	int *arr;

	i = 0;
	init_list(list);
	printf("%p\n", list);
	printf("%p\n", list->head);
	while (i < ints->length - 1)
	{
		arr = ints->ints;
		new_node = create_node(arr[i], i, 0);
		if (!list)
			add_first(list, &new_node);
		else
			add_last(list, &new_node);
	}

	return (*(list));
}