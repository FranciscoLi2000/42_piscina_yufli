#include <stdio.h>
#include <string.h>

void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	n;
	int	*ptr;
	int	x = 10;
	int	y = 3;
	int	div;
	int	mod;
	int	arr[5] = {5, 2, 8, 1, 4};
	int	size = 5;

	/* 1. ft_ft */
	ptr = &n;
	ft_ft(ptr);
	printf("ft_ft: n = %d (expected 42)\n", n);

	/* 2. ft_ultimate_ft */
	int	*p1 = &n;
	int	**p2 = &p1;
	int	***p3 = &p2;
	int	****p4 = &p3;
	int	*****p5 = &p4;
	int	******p6 = &p5;
	int	*******p7 = &p6;
	int	********p8 = &p7;
	int	*********p9 = &p8;
	ft_ultimate_ft(p9);
	printf("ft_ultimate_ft: n = %d (expected 42)\n", n);

	/* 3. ft_swap */
	x = 7;
	y = 9;
	ft_swap(&x, &y);
	printf("ft_swap: x = %d, y = %d (expected 9, 7)\n", x, y);

	/* 4. ft_div_mod */
	ft_div_mod(17, 5, &div, &mod);
	printf("ft_div_mod: div = %d, mod = %d (expected 3, 2)\n", div, mod);

	/* 5. ft_ultimate_div_mod */
	x = 17;
	y = 5;
	ft_ultimate_div_mod(&x, &y);
	printf("ft_ultimate_div_mod: x = %d, y = %d (expected 3, 2)\n", x, y);

	/* 6. ft_putstr and 7. ft_strlen */
	char	*s = "Hello, Norminette!\n";
	printf("ft_putstr:\n");
	ft_putstr(s);
	printf("\nft_strlen: %d (expected %zu)\n", ft_strlen(s), strlen(s));

	/* 8. ft_rev_int_tab */
	printf("Original array:\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	ft_rev_int_tab(arr, size);
	printf("Reversed array:\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	/* 9. ft_sort_int_tab */
	ft_sort_int_tab(arr, size);
	printf("Sorted array:\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
