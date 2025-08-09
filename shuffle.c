/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:42:44 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/09 17:42:54 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	shuffle(int *array, int n)
{
	int	j;
	int	tmp;

	for (int i = n - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

int	main(void)
{
	int	N;
	int	arr[100];

	N = 100;
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	srand(time(NULL));
	shuffle(arr, N);
	for (int i = 0; i < N; i++)
	{
		printf("%d", arr[i]);
		if (i != N - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}
