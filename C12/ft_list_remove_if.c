#include "ft_list.h"

void	ft_list_remove_if(t_list **lst, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*temp;

	while (*lst && cmp((*lst)->data, data_ref) == 0)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp->data);
		free(temp);
	}
	curr = *lst;
	while (curr && curr->next)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			temp = curr->next;
			curr->next = temp->next;
			free(temp->data);
			free(temp);
		}
		else
			curr = curr->next;
	}
}
