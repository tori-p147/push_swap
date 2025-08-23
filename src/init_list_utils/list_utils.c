/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:17:07 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:18:47 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, int order)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->order = order + 1;
	new_node->flag = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*remove_head(t_llist *list)
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

void	add_node(t_llist *list, t_node *new_node)
{
	if (list->size == 0)
		add_front(list, new_node);
	else
		add_last(list, new_node);
}
