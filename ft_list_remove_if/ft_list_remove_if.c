#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	
	if (begin_list == NULL || *begin_list == NULL)
		return ;
	t_list *copy = *begin_list;//make a copy 

	if (cmp(copy->data, data_ref) == 0)//apply the given function on the copy and if equal found
	{
		*begin_list = copy->next;//turn the next poiter of the copy into head of org 
		free(copy);//free the node
		ft_list_remove_if(begin_list, data_ref, cmp);//keep doing it as long as the cmp result is different
	}
	else//whenever the function resullt is not 0
	{
		copy = *begin_list;//make the copy
		ft_list_remove_if(&copy->next, data_ref, cmp);//start checking again from the next node coz we wont remove it
	}
}
// if there is a no else, you cant pass the Moulinette