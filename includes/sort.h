/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:18:40 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/21 22:36:56 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

typedef struct s_cmd_list	t_cmd_list;
typedef struct s_array		t_array;
typedef struct s_node		t_node;
typedef struct s_llist		t_llist;
typedef struct s_all		t_all;

void						conbine_cmd_list(t_cmd_list *cmd_list);
void						check_capacity(t_all *all, t_cmd_list *cmd_list);
int							stack_contains_next_with_0_flag(t_llist *stack,
								int next, int flag);
void						process_a_flag(t_all *all, t_cmd_list *cmd_list);
void						process_b(t_all *all, t_cmd_list *cmd_list);
void						update_flag(t_all *all);
int							is_next_blocked(t_llist *stack, int next);
int							stack_contains_flag(t_llist *stack, int flag);
int							calculate_mid_order_for_flag(t_llist *stack,
								int flag, int next);
int							get_next_value(t_node *node, t_llist *list);
int							exit_error_big_sort(t_all *all, char **strs);
int							exit_create_list_error(t_all *all, t_llist *stack_a,
								t_llist *stack_b, t_array *ints);
void						free_strs(char **str);
void						push_a(t_all *all);
void						push_b(t_all *all);
void						rotate(t_llist *stack_a);
void						reverse_rotate(t_llist *stack);
void						swap_values(t_node *first, t_node *second);
void						swap(t_llist *stack);
int							get_min_index(t_llist *stack_a);
int							get_max_index(t_llist *stack_b);
void						shift_min_to_head(t_all *all, t_cmd_list *cmd_list);
void						sort3(t_all *all, t_cmd_list *cmd_list);
void						sort4(t_all *all, t_cmd_list *cmd_list);
void						sort5(t_all *all, t_cmd_list *cmd_list);
void						sort_rest(t_all *all, int unsort_nums_amount,
								t_cmd_list *cmd_list);
// int						get_max_order(t_llist *stack_a);
int							sort_small(t_all *all);
void	sort_big(t_all *all, t_cmd_list *cmd_list);
void						sort_main(t_all *all);
#endif
