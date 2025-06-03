#include <stdio.h>
#include "ft_stock_str.h"

void	ft_show_tab(t_stock_str *par);
t_stock_str	*ft_strs_to_tab(int ac, char **av);

void	free_stock_strs(t_stock_str *array)
{
	int	i;

	i = 0;
	while (array[i].str != NULL)
	{
		free(array[i].copy);
		i++;
	}
	free(array);
}

int	main(int argc, char **argv)
{
	t_stock_str	*array;

	array = ft_strs_to_tab(argc - 1, argv + 1);
	if (!array)
		return (1);
	ft_show_tab(array);
	free_stock_strs(array);
	return (0);
}
