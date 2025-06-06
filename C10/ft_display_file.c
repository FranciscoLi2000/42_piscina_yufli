#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE];

	if (argc < 2)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, bytes);
	close(fd);
	return (0);
}
