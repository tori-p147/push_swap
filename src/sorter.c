/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:38:58 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/29 17:15:33 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_array *ints)
{
	int		tmp;
	bool	is_sorted;
	int		i;
	int		*arr;

	is_sorted = false;
	printf("start sort\n");
	while (!is_sorted)
	{
		is_sorted = true;
		i = 0;
		while (i < ints->length - 1)
		{
			arr = ints->ints;
			// ft_printf("arr[%d] before: %d\n", i, arr[i]);
			if (arr[i] > arr[i + 1])
			{
				is_sorted = false;
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			// ft_printf("arr[%d] after: %d\n", i, arr[i]);
			i++;
		}
	}
	for (int j = 0; j < ints->length; j++)
		ft_printf("sorted[%d] = %d\n", j, ints->ints[j]);
	printf("end sort\n");
}
