#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int first_arg;
int *tab;
int size;

void print_subset(int subsize, int *subset)
{
	int i = 0;
	while (i < subsize)
	{
		printf("%d", subset[i]);
		if (i < subsize - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}
int calcul_subset(int *subset, int subsize)
{
	int i = 0;
	int sum = 0;
	while (i < subsize)
	{
		sum = sum + subset[i];
		i++;
	}
	return (sum);
}
void solve(int *subset, int current_index, int subsize)
{
	if (current_index == size)
	{
		if (calcul_subset(subset, subsize) == first_arg && subsize != 0)
			print_subset(subsize, subset);
		return ;
	}
	solve(subset, current_index + 1, subsize);
	subset[subsize] = tab[current_index];
	solve(subset + 1, current_index + 1, subsize);
}
int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		printf("\n");
		return (0);
	}
	first_arg = atoi(argv[1]);
	size = argc - 2;
	tab = malloc(sizeof(int) * size);
	int *subset = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		tab[i] = atoi(argv[i + 2]);
	int current_index = 0;
	int subsize = 0;
	solve(subset, current_index, subsize);
}