
int	ft_strlen(char *str);

int	ft_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str && !ft_strchr(charset, *str))
		{
			count++;
			while (*str && !ft_strchr(charset, *str))
				str++;
		}
	}
	return (count);
}

char	*ft_strchr(char *str, int c);

char	*ft_empty_string(void)
{
	char	*str;

	str = malloc(1 * sizeof(char));
	if (str)
		str[0] = '\0';
	return (str);
}

char	*ft_copy_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_empty_string());
	if (len > s_len - start)
		len = s_len - start;
	return (ft_copy_substr(s, start, len));
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	result = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str && !ft_strchr(charset, *str))
		{
			len = 0;
			while (str[len] && !ft_strchr(charset, str[len]))
				len++;
			result[i++] = ft_substr(str, 0, len);
			str += len;
		}
	}
	result[i] = NULL;
	return (result);
}
