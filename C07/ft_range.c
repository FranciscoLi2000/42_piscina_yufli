#include <stdlib.h>
#include <stddef.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	len;
	int	i;

	if (min < max)
		len = max - min + 1;
	else
		len = min - max + 1;
	range = (int *)malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (min < max)
			range[i] = min++;
		else
			range[i] = min--;
		i++;
	}
	return (range);
}
