#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

// void print_node(t_list *a)
// {
// 	t_list *tmp;
// 	tmp = a;
// 	while (tmp)
// 	{
// 		printf("%ld:data, %ld:next", tmp->data, tmp->next);
// 		tmp = tmp->next;
// 	}
// }
// int main()
// {
// 	t_list *test;
// 	test->data = 'a';
// 	test->next = 'b';
// 	print_node(test);
// 	ft_list_foreach(test, void (*f)(void *));
// 	print_node(test)
// }