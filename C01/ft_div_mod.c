/*
4. ft_div_mod: Division and remainder

Theory

Compute a / b and a % b. Store the quotient in *div and the remainder in *mod. Both div and mod are pointers to where results should be stored.

*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}
