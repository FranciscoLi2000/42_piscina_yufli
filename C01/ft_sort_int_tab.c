/*
9. ft_sort_int_tab: Sort an integer array (ascending)

Theory

Implement a simple sorting algorithm (e.g., bubble sort): repeatedly traverse the array, swapping adjacent out-of-order elements until no swaps occur.

*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}
