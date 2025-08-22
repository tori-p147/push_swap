/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:28:27 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/22 18:18:41 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "sort.h"

char	**parse_nums(t_nums *nums, char *arg);
int		validate(int argc, char **argv, t_array *unsorted_ints);
int		free_and_return_error_validation(t_nums *nums, int *ints);
void	sort(t_array *ints);
int		is_sorted_stack(t_llist *stack);

#endif