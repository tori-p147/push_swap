/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:17:34 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/14 16:12:28 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_llist	*list_a;
	t_array	unsorted_ints;
	t_all	*all;

	if (!validate(argc, argv, &unsorted_ints))
		return (1);
	list_a = NULL;
	all = NULL;
	all = create_all(all, list_a, &unsorted_ints);
	sort_main(all);
	return (0);
}
