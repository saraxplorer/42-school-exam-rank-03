#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int count_str(char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && str[i] != ' ')
                i++;
        }
    }
     return (count);
}

char *ft_strncpy(char *copy, char *org, int n)
{
    int i = 0;
    while (n > i && org[i])
    {
        copy[i] = org[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
void free_array(int i, char **array)
{
    while(i > 0)
    {
        i--;
        free(array[i]);
    }
    free(array);
}
char **ft_split(char *str)
{
    int i = 0;
    int start = 0;
    int k = 0;

    int sub_num = count_str(str);
    char **array = (char**)malloc(sizeof(char*) * (sub_num) + 1);
    while (str[i])
    {
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
            i++;
        start = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\r')
            i++;
        if (i > start)
        {
            array[k] = (char*)malloc(sizeof(char) * (i - start));
            if (array[k]== NULL)
                free_array(k, array);
            ft_strncpy(array[k], &str[start], i - start);
            k++;
        }
    }
    array[k]= NULL;
    return (array);
}
void ft_putstr(char *str)
{
    int i =0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    { 
        char **array = ft_split(argv[1]);
        int j = 0;
        while(array[j])
        {
            printf("array::%s\n", array[j]);
            j++;
        }
        int i  = 1;
        while (array[i])
        {
            ft_putstr(array[i]);
            write(1, " ", 1);
            i++;
        }
        ft_putstr(array[0]);
    }
    write(1, "\n", 1);
}