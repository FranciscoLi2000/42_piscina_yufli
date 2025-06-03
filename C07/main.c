#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
/*	int	min;
	int	max;
	int	*tab;
	int	size;
	int	i;

	min = 100;
	max = 120;
	size = ft_ultimate_range(&tab, min, max);
	i = 0;
	while (i < max - min)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\nSize: %d\n", size);*/

	(void)argc;
	(void)argv;
	char	*s;

	s = fgets(s, sizeof(char), stdin);
	str = ft_strjoin(argc - 1, argv, " ");
	printf("Joined string: %s\n", str);
	free(str);
	return (0);
}
