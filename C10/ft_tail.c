#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <libgen.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_isdigit(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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

int	ft_tail(char *filename, int bytes, char *prog_name)
{
	int		fd;
	ssize_t	bytes_read;
	char	*buffer;
	ssize_t	file_size;
	ssize_t	offset;
	ssize_t	read_bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_display_error(prog_name, filename));
	file_size = 0;
	while ((bytes_read = read(fd, NULL, 0)) >= 0)
	{
		char	tmp[1024];
		ssize_t	n;

		lseek(fd, file_size, SEEK_SET);
		n = read(fd, tmp, sizeof(tmp));
		if (n <= 0)
			break ;
		file_size += n;
	}
	if (file_size == 0)
	{
		close(fd);
		return (0);
	}
	if (bytes > file_size)
		bytes = file_size;
	offset = file_size - bytes;
	if (lseek(fd, offset, SEEK_SET) < 0)
	{
		close(fd);
		return (ft_display_error(prog_name, filename));
	}
	buffer = malloc(bytes);
	if (!buffer)
	{
		close(fd);
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (1);
	}
	read_bytes = read(fd, buffer, bytes);
	if (read_bytes < 0)
	{
		free(buffer);
		close(fd);
		return (ft_display_error(prog_name, filename));
	}
	write(1, buffer, read_bytes);
	free(buffer);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*prog_name;
	int		bytes_to_show;
	int		i;
	int		error;

	prog_name = basename(argv[0]);
	error = 0;
	if (argc != 4 || ft_strcmp(argv[1], "-c") != 0 || !ft_isdigit(argv[2]))
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(prog_name, 2);
		ft_putstr_fd(" -c number file\n", 2);
		return (1);
	}
	bytes_to_show = atoi(argv[2]);
	if (bytes_to_show < 0)
		bytes_to_show = 0;
	i = 3;
	error = ft_tail(argv[i], bytes_to_show, prog_name);
	return (error);
}
