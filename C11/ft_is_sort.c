#include <stddef.h>

/* check if array is sorted based on comparison function */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	order;

	order = 0;
	i = 0;
	if (length < 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (order == 0) /* unknown */
				order = 1; /* ascending */
			else if (order == -1) /* descending */
				return (0);
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			if (order == 0)
				order = -1; /* descending */
			else if (order == 1)
				return (0);
		}
		i++;
	}
	return (1);
}
