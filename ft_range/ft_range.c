#include <stdlib.h>
int     *ft_range(int start, int end)
{
    int i = 0;
    int *result;
    if (start == end)
    {
        result = malloc(sizeof(int) * 2);
        result[i] = start;
    }
    else if (end > start)
    {
        result = malloc(sizeof(int) * (end - start + 1));
        while (end >= start)
        {
            result[i] = start; 
            start++;
            i++;
        }
    }
    else if (start > end)
    {
        result = malloc(sizeof(int) * (start - end + 1));
        while (start >= end)
        {
            result[i] = start; 
            start--;
            i++;
        }
    }
    return (result);

}
#include <stdio.h>
int main()
{
    int *x = ft_range(-3, 1);
    int size = 5;
    int i = 0;
    while(i < size)
    {
         printf("%d\n", x[i]);
         i++;
    }
    
}