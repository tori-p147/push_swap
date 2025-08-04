/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:18:40 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/04 22:53:43 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

typedef struct s_array	t_array;
typedef struct s_node	t_node;
typedef struct s_llist	t_llist;
typedef struct s_all	t_all;

int						exit_error_big_sort(t_all *all, char **strs, int i);
int						exit_create_list_error(t_all *all, t_llist *stack_a,
							t_llist *stack_b, t_array *ints);
void	free_strs(char **str, int i);
char					*push_a(t_all *all);
char					*push_b(t_all *all);
char					*rotate(t_llist *stack_a, char stack_name);
char					*reverse_rotate(t_llist *stack, char stack_name);
void					swap_values(t_node *first, t_node *second);
char					*swap(t_llist *stack, char stack_name);
int						get_min_index(t_llist *stack_a);
void					shift_min_to_head(t_llist *stack_a);
void					sort2(t_llist *stack_a);
void					sort3(t_all *all);
void					sort4(t_all *all);
void					sort5(t_all *all);
void					sort_rest(t_all *all, int unsort_nums_amount);
t_node					*get_max_node(t_llist *stack_a);
void					sort_big(t_all *all);
void					sort_main(t_all *all);

#endif
