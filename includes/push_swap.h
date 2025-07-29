/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:11 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/29 22:44:04 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

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
	int				min_a;
	int				med;
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

int					is_valid_nums(t_nums *nums, t_array *ints);
char				**parse_nums(t_nums *nums, char *arg);
int					is_integers(t_nums *nums, t_array *ints);
int					return_error(char *msg, t_nums *nums, int *ints);
int					is_nums_uniq(t_nums *nums);
int					check_duplicate(t_nums *nums);
int					main(int argc, char **argv);
void				free_nums(t_nums *nums);
int					is_sorted(t_array *ints);
int					count_nums(char **nums);
t_all				*create_all(t_all *all, t_llist *list, t_array *ints);
t_llist				*create_list(t_llist *list, t_array *ints);
t_llist				*init_list(t_llist *list);
void				sort(t_array *ints);
t_llist				*fill_list(t_llist *list, t_array *unsorted,
						t_array *sorted);
void				add_front(t_llist *list, t_node *new_node);
void				add_back(t_llist *list, t_node *new_node);
t_node				*create_node(int value, int order, int flag);
void				free_list(t_llist *list);
void				free_all(t_all *all);

#endif
