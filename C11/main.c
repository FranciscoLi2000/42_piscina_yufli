#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void	ft_foreach(int *tab, int length, void (*f)(int));
int	*ft_map(int *tab, int length, int (*f)(int));
int	ft_any(char **tab, int (*f)(char *));
int	ft_count_if(char **tab, int length, int (*f)(char *));
int	ft_is_sort(int *tab, int length, int (*f)(int, int));
void	ft_sort_string_tab(char **tab);
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

void	print_int(int n)
{
	printf("%d\n", n);
}

int	square(int n)
{
	return (n * n);
}

int	is_digit_string(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	strcmp_int(int a, int b)
{
	return (a - b);
}

int	strcmp_str(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return *(unsigned char*)a - *(unsigned char*)b;
}

int	is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	nums[] = {1, 2, 3, 4, 5};
	int	*squares;
	int	i;
	int	count;
	int	j;

	if (argc < 2)
	{
		printf("ft_foreach:\n");
		ft_foreach(nums, 5, &print_int);
		printf("\nft_map (squares):\n");
		squares = ft_map(nums, 5, &square);
		i = 0;
		while (i < 5)
		{
			printf("%d\n", squares[i]);
			i++;
		}
		free(squares);
		if (ft_is_sort(nums, 5, &strcmp_int))
			printf("The numbers are sorted.\n");
		else
			printf("Not sorted.\n");
		return (0);
	}
	else if (argc > 1)
	{
		if (ft_any(argv + 1, &is_numeric))
			printf("The string contains number character.\n");
		else
			printf("The string doesn't have number.\n");
		count = ft_count_if(argv + 1, argc - 1, &is_numeric);
		printf("Count of numeric strings: %d\n", count);
		ft_sort_string_tab(argv + 1);
		j = 1;
		while (j < argc)
		{
			printf("%s\n", argv[j]);
			j++;
		}
		printf("If they are strings, let us sort them!\n");
		ft_advanced_sort_string_tab(argv + 1, &strcmp_str);
		j = 1;
		while (j < argc)
		{
			printf("%s ", argv[j]);
			j++;
		}
		printf("\n");
	}
	return (0);
}
