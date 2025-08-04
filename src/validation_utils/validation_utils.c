/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:36:53 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/04 18:05:25 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_nums(t_nums *nums, t_array *ints)
{
	if (!is_nums_uniq(nums))
		return (free_and_return_error_validation(nums, NULL));
	ints->ints = malloc(sizeof(int) * count_nums(nums->nums));
	if (!ints->ints)
		return (free_and_return_error_validation(nums, ints->ints));
	if (!is_integers(nums, ints))
		return (free_and_return_error_validation(nums, ints->ints));
	free_nums(nums);
	ft_printf("ints.length = %d \n", ints->length);
	if (is_sorted(ints->ints, ints->length))
	{
		free(ints->ints);
		return (0);
	}
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
	// ft_printf("length %d\n", ints->length);
	// for (int j = 0; j < ints->length; j++)
	// 	ft_printf("%d\n", ints->ints[j]);
	// ft_printf("%s\n", "----");
	return (1);
}

int	is_sorted(int *ints, int length)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 1;
	tmp = ints[0];
	while (i < length)
	{
		if (tmp > ints[i])
			return (0);
		tmp = ints[i];
		ft_printf("valid ints[%d] = %d\n", i, ints[i]);
		i++;
	}
	return (1);
}
