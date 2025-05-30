#include <unistd.h>

void	ft_putchar(char c);

static void	print_comb(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (1)
	{
		print_comb(tab, n);
		i = n - 1;
		while (i >= 0)
		{
			if (tab[i] < 9 - (n - 1 - i))
			{
				tab[i]++;
				while (i < n - 1)
				{
					tab[i + 1] = tab[i] + 1;
					i++;
				}
				break ;
			}
			i--;
		}
		if (i < 0)
			break ;
	}
}
