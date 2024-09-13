#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	
	if (begin_list == NULL || *begin_list == NULL)//if the array or first element of array is NULL
		return ;
	t_list *copy = *begin_list;//make a copy of the first element of the array 

	if (cmp(copy->data, data_ref) == 0)//apply the given function on the copy and if equal found
	{
		*begin_list = copy->next;//change the head of org element into next node of copy 
		free(copy);//free the head of copy
		ft_list_remove_if(begin_list, data_ref, cmp);//keep doing it as long as the cmp result is different
	}
	else//whenever the function resullt is not 0
	{
		copy = *begin_list;//make the copy//probably not necessary
		ft_list_remove_if(&copy->next, data_ref, cmp);//start checking again from the next node coz we wont remove it
	}
}
// if there is a no else, you cant pass the Moulinette

else
	{
		copy = copy->next;
		ft_list_remove_if(&copy, data_ref, cmp);
	}

//This block might also work. here I move to the next node and just send it again
