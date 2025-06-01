#include <unistd.h>

int	g_count = 0;

void	print_board(int board[10])
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int board[10], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || col - i == row - board[i]
			|| col - i == board[i] - row)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int col)
{
	int	row;

	if (col == 10)
	{
		print_board(board);
		g_count++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];

	solve(board, 0);
	return (g_count);
}
