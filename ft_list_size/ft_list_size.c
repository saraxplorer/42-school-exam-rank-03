#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}
int main()
{
    // Create nodes statically
    t_list node1 = { (void*)1, NULL }; // Node 1 with data = 1
    t_list node2 = { (void*)2, NULL }; // Node 2 with data = 2
    t_list node3 = { (void*)3, NULL }; // Node 3 with data = 3

    // Link nodes
    node1.next = &node2;
    node2.next = &node3;
	node3.next = NULL;

    // Calculate size
    int size = ft_list_size(&node1);
    printf("List size: %d\n", size);

    return 0;
}