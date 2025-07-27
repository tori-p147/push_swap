/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:11 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/27 22:27:28 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int		value;
	int		order;
	int		flag;
	t_list	*next;
	t_list	*prev;
}			s_list;

char		**parse_nums(char *arg);
int			validate_nums(char **nums);
void		error(char *msg);
int			*check_int_range_and_create_array(char **nums);
int			check_duplicate(char **nums);
int			main(int argc, char **argv);
void		free_nums(char **nums);
int			is_sorted(int *ints);
int			count_nums(char **nums);

#endif