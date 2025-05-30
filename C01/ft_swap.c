/*
3. ft_swap: Swapping two integers

Theory

To swap two integers, pass their addresses (int *a, int *b). Use a temporary variable to hold one value during the swap.

*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
