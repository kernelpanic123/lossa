/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:00:56 by abtouait          #+#    #+#             */
/*   Updated: 2025/09/11 02:19:10 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int first_arg;
int size;
int *tab;

void	print_subset(int subsize, int *subset)
{
	int i = 0;
	while (i < subsize)
	{
		printf("%d", subset[i]);
		if (i < subsize -1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int calcul_subset_sum(int subsize, int *subset)
{
	int sum = 0;
	int i = 0;
	while (i < subsize)
	{
		sum = sum + subset[i];
		i++;
	}
	return sum;
}

void solve(int subsize, int current_index, int *subset)
{
	if (current_index == size)
	{
		if (calcul_subset_sum(subsize, subset) == first_arg && subsize != 0)
			print_subset(subsize, subset);
		return ;
	}
	// 1) on ne prend pas nums[current_index]
	solve(subsize, current_index + 1, subset);
	// 2) on prend nums[current_index]
	subset[subsize] = tab[current_index]; 
	solve(subsize + 1, current_index + 1, subset);
}

int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		printf("\n");
        return 0;
	}
	first_arg = atoi(argv[1]);
	size = argc - 2;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return 1;
	int *subset = calloc(size, sizeof(int));
	if (!subset)
	{
		free(tab);
		return 1;
	}
	for (int i = 0; i < size; i++)
		tab[i] = atoi(argv[i + 2]);
	int subsize = 0;
	int current_index = 0;
	solve(subsize, current_index, subset);
	free(tab);
	free(subset);
}