#include "ft_list.h"

static void	swap_node(t_list *a, t_list *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*curr;
	int		swap;

	if (!lst)
		return (NULL);
	swap = 1;
	while (swap)
	{
		swap = 0;
		curr = lst;
		while (curr->next)
		{
			if (cmp(curr->data, curr->next->data) == 0)
			{
				swap_node(curr, curr->next);
				swap = 1;
			}
			curr = curr->next;
		}
	}
}
