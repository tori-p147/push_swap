/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:36:53 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/27 22:33:34 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_nums(char **nums)
{
	int	*ints;

	if (!check_duplicate(nums))
		return (0);
	ints = check_int_range_and_create_array(nums);
	if (!ints)
		return (0);
	ft_printf("%d", *ints);
	if (is_sorted(ints))
		return (0);
	return (1);
}

int	check_duplicate(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i] != NULL)
	{
		j = i + 1;
		while (nums[j] != NULL)
		{
			if (ft_strncmp(nums[i], nums[j], 11) == 0)
			{
				// printf("compare nums[%d] = %s and nums[%d] = %s\n", i,
				// nums[i],
				// 	j, nums[j]);
				free_nums(nums);
				error("args have duplicate");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	*alloc_ints_arr(int n)
{
	return ((int *)malloc(sizeof(int) * n));
}
int	count_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i] != NULL)
		i++;
	return (i);
}

int	*check_int_range_and_create_array(char **nums)
{
	int		i;
	long	num;
	bool	is_not_integer;
	int		*ints;
	int		nums_count;

	i = 0;
	nums_count = count_nums(nums);
	ints = malloc(sizeof(int) * nums_count);
	if (!ints)
	{
		free_nums(nums);
		return (NULL);
	}
	while (nums[i] != NULL)
	{
		is_not_integer = false;
		num = ft_atoi_long(nums[i], &is_not_integer);
		// printf("nums[%d] = %ld\n", i, num);
		// printf("bool = %d\n", is_not_integer);
		if (is_not_integer || INT_MIN > num || num > INT_MAX)
		{
			free_nums(nums);
			free(ints);
			error("arg(s) not integer");
			return (NULL);
		}
		ints[i] = num;
		ft_printf("%d\n", ints[i]);
		i++;
	}
	i = 0;
	return (ints);
}

int	is_sorted(int *ints)
{
	int	*ptr;
	int	tmp;

	ptr = ints;
	tmp = 0;
	while (*ints)
	{
		printf("ints[%d]\n", *ints);
		if (tmp != 0 && tmp > *ints)
		{
			free(ptr);
			return (1);
		}
		tmp = *ints;
		ints++;
	}
	error("numbers are sorted");
	free(ptr);
	return (0);
}
