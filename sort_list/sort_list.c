#include "ft_list.h"


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{	
	int temp;
	t_list *copy;

	copy = lst;//initialize head
	
	while (lst && lst->next)
	{
		// Apply the given function with *cmp to current and next node, where 0 means not sorted
		if ((*cmp)(lst->data, lst->next->data) == 0)//if not sorted
		{
			temp = lst->data;//swap
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = copy;//reset lst to head to check from the beginning again
		}
		else //if sorted, we move to the next node
			lst = lst->next;
	}
	return (copy);
}
