#include <unistd.h>

int	ft_strlen(char *str);

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	c;
	int		base_len;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putnbr_base(-(nbr / base_len), base);
		ft_putnbr_base(-(nbr % base_len), base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	c = base[nbr % base_len];
	write(1, &c, 1);
}
