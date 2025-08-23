/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:11 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/23 18:22:36 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "sort.h"
# include <stdlib.h>
# include <unistd.h>

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RR "rr\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_cmd_list
{
	int				cmd_i;
	int				capacity;
	char			**str_arr;

}					t_cmd_list;

typedef struct s_node
{
	int				value;
	int				order;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_llist
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_llist;

typedef struct s_all
{
	t_llist			*stack_a;
	t_llist			*stack_b;
	int				mid;
	int				max;
	int				next;
	int				flag;
}					t_all;

typedef struct s_nums
{
	char			**nums;
	bool			allocated;
}					t_nums;

typedef struct s_array
{
	int				*ints;
	int				length;
}					t_array;

t_node				*create_node(int value, int order);
t_node				*remove_head(t_llist *list);
void				add_front(t_llist *list, t_node *new_node);
void				add_node(t_llist *list, t_node *new_node);
int					is_next_found(t_llist *stack, int next);
int					count_flag_elements(t_llist *stack, int flag);
int					find_max_flag(t_llist *stack);
int					is_sorted_stack(t_llist *stack);
int					get_min_count(int pb_count, int pa_count);
void				first_process(t_all *all, t_cmd_list *cmd_list);
void				check_strdup(t_all *all, t_cmd_list *cmd_list);
void				do_push_b(t_all *all, t_cmd_list *cmd_list);
void				do_push_a(t_all *all, t_cmd_list *cmd_list);
void				do_swap_a(t_all *all, t_cmd_list *cmd_list);
void				do_swap_b(t_all *all, t_cmd_list *cmd_list);
void				init_str_arr(t_all *all, t_cmd_list *cmd_list);
void				do_reverse_rotate_a(t_all *all, t_cmd_list *cmd_list);
void				do_reverse_rotate_b(t_all *all, t_cmd_list *cmd_list);
void				do_rotate_a(t_all *all, t_cmd_list *cmd_list);
void				do_rotate_b(t_all *all, t_cmd_list *cmd_list);
int					validate(int argc, char **argv, t_array *unsorted_ints);
int					free_and_return_error_validation(t_nums *nums, int *ints);
int					is_valid_nums(t_nums *nums, t_array *ints);
char				**parse_nums(t_nums *nums, char *arg);
int					is_integers(t_nums *nums, t_array *ints);
int					is_nums_uniq(t_nums *nums);
int					check_duplicate(t_nums *nums);
int					main(int argc, char **argv);
void				free_nums(t_nums *nums);
int					is_sorted(int *ints, int length);
int					count_nums(char **nums);
t_all				*create_all(t_all *all, t_llist *list, t_array *ints);
t_llist				*create_list(t_llist *list, t_array *ints);
t_llist				*init_list(t_llist *list);
void				sort(t_array *ints);
t_llist				*fill_list(t_llist *list, t_array *unsorted,
						t_array *sorted);
void				add_front(t_llist *list, t_node *new_node);
void				add_last(t_llist *list, t_node *new_node);
t_node				*create_node(int value, int order);
void				free_strs(t_cmd_list *cmd_list);
void				free_list(t_llist *list);
void				free_all(t_all *all);
t_node				*remove_first(t_llist *list);
t_node				*remove_head(t_llist *list);

#endif
