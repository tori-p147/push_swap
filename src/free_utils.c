/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:56:22 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/07/28 16:23:48 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nums(t_nums *nums)
{
	char	**ptr;

	printf("%d\n", nums->allocated);
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
