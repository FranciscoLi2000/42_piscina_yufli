#include <stdlib.h>
#include <stddef.h>

/* apply a function to every element and returns a new array with results */
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	result = (int *)malloc(length * sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
