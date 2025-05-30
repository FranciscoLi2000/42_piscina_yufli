/*
5. ft_ultimate_div_mod: In-place div and mod

Theory

Take pointers to two ints, a and b. Compute quotient and remainder of *a / *b. Write quotient back to *a and remainder to *b.

*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	q;
	int	r;

	if (*b == 0)
		return ;
	q = *a / *b;
	r = *a % *b;
	*a = q;
	*b = r;
}
