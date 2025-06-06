#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <libgen.h>

#define BYTES_PER_LINE 16

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	ft_display_error(char *prog_name, char *filename)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_print_line(unsigned char *buffer, ssize_t size, unsigned long offset)
{
	ssize_t	i;
	char	offset_str[12];
	snprintf(offset_str, sizeof(offset_str), "%08lx  ", offset);
	write(1, offset_str, 10);
	i = 0;
	while (i < BYTES_PER_LINE)
	{
		if (i < size)
			ft_print_hex(buffer[i]);
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	write(1, " |", 2);
	i = 0;
	while (i < size)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	bytes_read;
	unsigned char	buffer[BYTES_PER_LINE];
	unsigned long	offset;
	char	*prog_name;

	offset = 0;
	prog_name = basename(argv[0]);
	if (argc != 3 || strcmp(argv[1], "-C") != 0)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(prog_name, 2);
		ft_putstr_fd(" -C filename\n", 2);
		return (1);
	}
	fd = open(argv[2], O_RDONLY);
	if (fd < 0)
	{
		ft_display_error(prog_name, argv[2]);
		return (1);
	}
	while ((bytes_read = read(fd, buffer, BYTES_PER_LINE)) > 0)
	{
		ft_print_line(buffer, bytes_read, offset);
		offset += bytes_read;
	}
	if (bytes_read < 0)
	{
		ft_display_error(prog_name, argv[2]);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
