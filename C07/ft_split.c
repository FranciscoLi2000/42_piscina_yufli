
int	ft_strlen(char *str);

int	ft_count_words(char *str, char c)
{
}

char	*ft_strchr(char *str, int c);

char	*ft_substr(char *str, char start, int len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(str);
	if (start >= s_len)
	{
		sub = (char *)malloc(1);
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if ()
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && ft_strchr(*s, c))
			s++;
		if (*s && !ft_strchr(*s, c))
		{
			len = 0;
			while (s[len] && !ft_strchr(s[len], c))
				len++;
			result[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}
