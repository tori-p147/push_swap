/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:38:58 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/04 15:11:32 by vmatsuda         ###   ########.fr       */
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
	while (!is_sorted)
	{
		is_sorted = true;
		i = 0;
		while (i < ints->length - 1)
		{
			arr = ints->ints;
			if (arr[i] > arr[i + 1])
			{
				is_sorted = false;
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
	}
}
