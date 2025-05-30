/*
1. ft_ft: Setting an integer via pointer

Theory

A pointer in C stores the address of a variable. By dereferencing a pointer, you access or modify the value stored at that address. The function ft_ft receives an int *nbr and sets the value at that address to 42.

*/

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
