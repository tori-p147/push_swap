/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:11 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/06 16:11:45 by vmatsuda         ###   ########.fr       */
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

typedef struct s_node
{
	int				value;
	int				order;
	int				chunk;
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
	int				max;
	int				mid;
	int				next;
	int				chunk;
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
t_node				*create_node(int value, int order, int chunk);
void				free_list(t_llist *list);
void				free_all(t_all *all);
t_node				*remove_first(t_llist *list);

#endif
