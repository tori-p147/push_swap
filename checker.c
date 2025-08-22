/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:27:17 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 17:15:24 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_state(t_all *all, char *msg, int i)
{
	t_node	*ptr_head_a;
	t_node	*ptr_head_b;

	ptr_head_a = all->stack_a->head;
	while (ptr_head_a)
	{
		ft_printf("a %s %d loop [%d] =%d flag =%d\n ", msg, i,
			ptr_head_a->order, ptr_head_a->value, ptr_head_a->flag);
		ptr_head_a = ptr_head_a->next;
	}
	ptr_head_b = all->stack_b->head;
	while (ptr_head_b)
	{
		ft_printf("b %s %d loop [%d] = %d flag =%d\n ", msg, i,
			ptr_head_b->order, ptr_head_b->value, ptr_head_b->flag);
		ptr_head_b = ptr_head_b->next;
	}
}

void	parse_operation(t_all *all, char *line)
{
	if (ft_strncmp(line, RA, 2) == 0)
		rotate(all->stack_a);
	else if (ft_strncmp(line, RB, 2) == 0)
		rotate(all->stack_b);
	else if (ft_strncmp(line, RR, 3) == 0)
	{
		rotate(all->stack_a);
		rotate(all->stack_b);
	}
	else if (ft_strncmp(line, SA, 3) == 0)
		swap(all->stack_a);
	else if (ft_strncmp(line, SB, 3) == 0)
		swap(all->stack_b);
	else if (ft_strncmp(line, SS, 3) == 0)
	{
		swap(all->stack_a);
		swap(all->stack_b);
	}
	else if (ft_strncmp(line, PA, 3) == 0)
		push_a(all);
	else if (ft_strncmp(line, PB, 3) == 0)
		push_b(all);
	else if (ft_strncmp(line, RRA, 3) == 0)
		reverse_rotate(all->stack_a);
	else if (ft_strncmp(line, RRB, 3) == 0)
		reverse_rotate(all->stack_b);
	else if (ft_strncmp(line, RRR, 3) == 0)
	{
		reverse_rotate(all->stack_a);
		reverse_rotate(all->stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_llist	*list_a;
	t_array	unsorted_ints;
	t_all	*all;
	char	*line;

	if (!validate(argc, argv, &unsorted_ints))
		return (1);
	list_a = NULL;
	all = NULL;
	all = create_all(all, list_a, &unsorted_ints);
	line = get_next_line(1);
	while (line != NULL)
	{
		parse_operation(all, line);
		print_state(all, "turn", 0);
		if (is_sorted_stack(all->stack_a) && all->stack_b->size == 0)
		{
			ft_printf("OK\n");
			free(all);
			return (0);
		}
		free(line);
		line = get_next_line(1);
	}
	print_state(all, "end", 0);
	ft_printf("KO\n");
	return (1);
}
