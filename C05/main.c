#include <stdio.h>

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

int	main(void)
{
	int	n;

	n = 16;
	printf("Iterative: 16! = %d\n", ft_iterative_factorial(n));
	printf("Recursive: 16! = %d\n", ft_recursive_factorial(n));
	printf("Iterative: 16 ^ 2 = %d\n", ft_iterative_power(n, 2));
	printf("Recursive: 16 ^ 2 = %d\n", ft_recursive_power(n, 2));
	printf("Fibonacci sum: %d\n", ft_fibonacci(n));
	printf("Sqrt: %d\n", ft_sqrt(n));
	if (ft_is_prime(n))
		printf("%d is a prime number.\n", n);
	else
		printf("%d is a prime number.\n", n);
	printf("The next prime number is %d\n", ft_find_next_prime(n));
//	printf("----------------------------------\n");
//	printf("The N-queens problem: %d\n", ft_ten_queens_puzzle());
	return (0);
}
