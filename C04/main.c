#include <stdio.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi(char *str);
int		ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	*s;
	char	*base;
	int		n;

	s = "2345";
	base = "0123456789ABCDEF";
	n = 42;
	printf("The base is %s (%d base)\n", base, ft_strlen(base));
	ft_putstr("The num string is ");
	ft_putstr(s);
	printf("\n");
	printf("After using ft_atoi_base, the num string is %d int\n", ft_atoi_base(s, base));
	ft_putstr("Another integer: ");
	ft_putnbr(n);
	printf("\n");
	ft_putnbr_base(n, base);
	printf("\n");
	return (0);
}
