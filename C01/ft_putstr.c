/*
6. ft_putstr: Printing a string

Theory

A string is a null-terminated char array. Iterate until \0, writing each character using write(1, ...) (or putchar if allowed). 42 typically uses the write syscall.

*/

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
