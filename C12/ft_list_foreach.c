#include "ft_list.h"

void	ft_list_foreach(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		if (lst->data != NULL)
			(*f)(lst->data);
		lst = lst->next;
	}
}
