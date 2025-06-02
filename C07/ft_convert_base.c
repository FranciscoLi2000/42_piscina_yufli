#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

int	ft_base_valid(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		result;
	int		base_len;
	char	*pos;

	i = 0;
	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((pos = ft_strchr(base, str[i])))
	{
		result = result * base_len + (pos - base);
		i++;
	}
	return (result * sign);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*str;
	int		base_len;
	int		num_len;
	long	nb;

	base_len = ft_strlen(base);
	num_len = num_len(n);
	nb = n;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[num_len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[--num_len] = (nb % base_len) + '0';
		n /= base_len;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_base_valid(base_from) || !ft_base_valid(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}
