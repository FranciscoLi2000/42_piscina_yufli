#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			print_hex((unsigned char)str[i]);
		i++;
	}
}
