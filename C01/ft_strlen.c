/*
7. ft_strlen: String length

Theory

Count characters until the null terminator \0. Return the count as int.

*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
