/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:36:53 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/29 18:06:00 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_nums(t_nums *nums, t_array *ints)
{
	if (!is_nums_uniq(nums))
		return (return_error("args have duplicate", nums, NULL));
	ints->ints = malloc(sizeof(int) * count_nums(nums->nums));
	if (!ints->ints)
		return (return_error("can`t allocate ints array\n", nums, ints->ints));
	if (!is_integers(nums, ints))
		return (return_error("arg(s) not integer\n", nums, ints->ints));
	if (is_sorted(ints))
		return (return_error("numbers are sorted\n", nums, ints->ints));
	free_nums(nums);
	return (1);
}

int	is_nums_uniq(t_nums *nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums->nums[i] != NULL)
	{
		j = i + 1;
		while (nums->nums[j] != NULL)
		{
			if (ft_strncmp(nums->nums[i], nums->nums[j], 11) == 0)
			{
				// printf("compare nums[%d] = %s and nums[%d] = %s\n", i,
				//	nums->nums[i],
				// 	j, nums->nums[j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i] != NULL)
		i++;
	return (i);
}

int	is_integers(t_nums *nums, t_array *ints)
{
	int		i;
	long	num;
	bool	is_not_integer;

	i = 0;
	while (nums->nums[i] != NULL)
	{
		is_not_integer = false;
		num = ft_atoi_long(nums->nums[i], &is_not_integer);
		// printf("nums[%d] = %ld\n", i, num);
		// printf("bool = %d\n", is_not_integer);
		if (is_not_integer || INT_MIN > num || num > INT_MAX)
			return (0);
		ints->ints[i] = (int)num;
		// ft_printf("%d\n", ints[i]);
		i++;
	}
	ints->length = i;
	printf("length %d\n", ints->length);
	for (int j = 0; j < ints->length; j++)
		ft_printf("%d\n", ints->ints[j]);
	printf("%s\n", "----");
	return (1);
}

int	is_sorted(t_array *ints)
{
	int	tmp;
	int i;

	tmp = 0;
	i = 0;
	// printf("length %d\n", ints->length);
	while (i < ints->length)
	{
		// printf("ints %d\n", ints->ints[i]);
		if (tmp != 0 && tmp > ints->ints[i])
			return (0);
		tmp = ints->ints[i];
		i++;
	}
	return (1);
}
