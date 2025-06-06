#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 30000

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_display_error(char *prog_name, char *filename)
{
	ft_putstr_fd(prog_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	ft_display_file(char *filename, char *prog_name)
{
	int		fd;
	ssize_t	bytes;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_display_error(prog_name, filename));
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, bytes);
	if (bytes < 0)
	{
		close(fd);
		return (ft_display_error(prog_name, filename));
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	error;

	if (argc < 2)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	error = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_display_file(argv[i], argv[0]) != 0)
			error = 1;
		i++;
	}
	return (error);
}
