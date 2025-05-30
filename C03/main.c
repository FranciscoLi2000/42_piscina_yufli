#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char s1[50] = "Parque del Retiro";
	char s2[50] = "Entorn la taula guarnida";
	char s3[50] = "Ricard era un noi";
	char s4[50] = "Arbres com un ramat pasturant entre prades";
	char	*found;
	unsigned int	res;

	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("ft_strncmp (10): %d\n", ft_strncmp(s3, s4, 10));
	ft_strcat(s1, s2);
	printf("ft_strcat: %s\n", s1);
	ft_strncat(s3, s4, 10);
	printf("ft_strncat (10): %s\n", s3);
	found = ft_strstr(s4, "ramat");
	if (found)
		printf("ft_strstr: found: %s\n", found);
	else
		printf("ft_strstr: not found\n");
	res = ft_strlcat(s1, s2, sizeof(s1));
	printf("ft_strlcat: %s (length: %u)\n", s1, res);
	return (0);
}
