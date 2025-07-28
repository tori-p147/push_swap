/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:56:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 21:05:58 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nums(t_nums *nums)
{
	char	**ptr;

	if (!nums->allocated)
		return;
	ptr = nums->nums;
	while (*nums->nums)
	{
		// printf("%s\n", *nums);
		free(*nums->nums);
		nums->nums++;
	}
	free(ptr);
	ptr = NULL;
	// printf("%p\n", ptr);
}
