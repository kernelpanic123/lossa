#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

void print_board(int n, int *board)
{
	int i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n -1)
			printf(" ");
		i++;
	}
	printf(" ");
}
int is_valid(int *board, int row, int col)
{
	int i = 0;
	while (i < row)
	{
		if (board[i] == col)
			return (0);
		if (board[i] -i == col - row)
			return (0);
		if (board[i] + i == col + row)
			return (0);
	}
	return (1);
}
void nqueen(int n, int *board, int row)
{
	int col = 0;

	if (row == n)
	{
		print_board(n, board);
		return ;
	}
	while (col < n)
	{
		if (is_valid(board, row, col))
		{
			board[row] = col;
			nqueen(n, board, row + 1);
		}
		col++;
	}
}