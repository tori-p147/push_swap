/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:18:40 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/31 18:43:08 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

typedef struct s_node	t_node;
typedef struct s_llist	t_llist;
typedef struct s_all	t_all;

char					*push_a(t_all *all);
char					*push_b(t_all *all);
char					*rotate(t_llist *stack_a, char stack_name);
char					*reverse_rotate(t_llist *stack, char stack_name);
void					swap_values(t_node *first, t_node *second);
char					*swap(t_llist *stack, char stack_name);
t_node					*get_min(t_llist *stack_a);
void					sort2(t_llist *stack_a);
void					sort3(t_all *all);
void					sort_main(t_all *all);

#endif
