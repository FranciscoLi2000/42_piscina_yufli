#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int nb);
void	ft_print_combn(int n);

int	main(void)
{
	char	ch;
	int		nb;

	ch = 'A';
	nb = 42;
	ft_putchar(ch);
	printf("\n-----------------------\n");
	ft_print_alphabet();
	printf("\n-----------------------\n");
	ft_print_reverse_alphabet();
	printf("\n-----------------------\n");
	ft_print_numbers();
	printf("\n-----------------------\n");
	ft_is_negative(-nb);
	printf("\n-----------------------\n");
	ft_print_comb();
	printf("\n-----------------------\n");
	ft_print_comb2();
	printf("\n-----------------------\n");
	ft_putnbr(nb);
	printf("\n-----------------------\n");
	ft_print_combn(4);
	printf("\n-----------------------\n");
	return (0);
}
