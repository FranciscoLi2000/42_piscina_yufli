/*
8. ft_rev_int_tab: Reverse an integer array

Theory

Reverse in place by swapping tab[i] with tab[size - 1 - i] up to the midpoint.

*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}
