#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_printable(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_uppercase(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putstr_non_printable(char *str);
void	*ft_print_memory(void *addr, unsigned int size);

#include <string.h>

int	main(void)
{
	char	*str;

	str = "Arranca la 84a Feria del Libro de Madrid: reinas que leen, escritores que firman y curiosos que miran";
/*	if (ft_str_is_numeric(str))
		printf("All characters are digits.\n");
	else
		printf("Some characters are not digits.\n");
	char *res = ft_strcapitalize(str);
	printf("%s\n", res);*/
	ft_print_memory((void *)str, strlen(str) + 1);
	return (0);
}
