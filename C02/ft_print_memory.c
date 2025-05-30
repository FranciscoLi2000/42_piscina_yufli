#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puthex(unsigned long n, int digits)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (digits > 1)
		ft_puthex(n / 16, digits - 1);
	ft_putchar(hex[n % 16]);
}

void	print_hex_content(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_puthex(ptr[i], 2);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	print_printable(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned char		*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_puthex((unsigned long)(ptr + i), 16);
		ft_putstr(": ");
		if (size - i >= 16)
		{
			print_hex_content(ptr + i, 16);
			print_printable(ptr + i, 16);
		}
		else
		{
			print_hex_content(ptr + i, size - i);
			print_printable(ptr + i, size - i);
		}
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
