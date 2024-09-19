#include <stdlib.h>
int     *ft_rrange(int start, int end)
{
    int i = 0;
    int *result;
    if (start == end)
    {
        result = malloc(sizeof(int) * 2);
        result[i] = start;
    }
    else if (end > start) //MUST BE "ELSE" If, only if WONT work!
    {
        result = malloc(sizeof(int) * (end - start + 1));
        while (end >= start)
        {
            result[i] = end; 
            end--;
            i++;
        }
    }
    else if (start > end)
    {
        result = malloc(sizeof(int) * (start - end + 1));
        while (start >= end)
        {
            result[i] = end; 
            end++;
            i++;
        }
    }
    return (result);

}
#include <stdio.h>
int main()
{
    int *x = ft_rrange(-1, 4);
    int size = 6;
    int i = 0;
    while(i < size)
    {
         printf("%d\n", x[i]);
         i++;
    }
    
}