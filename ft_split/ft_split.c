#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *copy, char *original, int n)
{
	int i = 0;

	while (n > i && original[i])
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int count_substrings(char *str)
{	
	int subs_num = 0;
	int i = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t')//remove spaces including initial
			i++;
		if (str[i])//If there is something in string after skipping space
		{
			subs_num++;//count 1
			while (str[i] && str[i] != ' ' && str[i] != '\r' && str[i] != '\t')//skip other letters in a string
				i++;
		}
	}
	return (subs_num);
}

void	free_array(int i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

char **ft_split(char *str)
{
	
	int i = 0;
	int j = 0;
	int k = 0;

	int substr_num = count_substrings(str);

	char **subs_array = (char **)malloc(sizeof(char *) * (substr_num + 1));
	if (subs_array == NULL)
		return NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')//remove spaces including initial
			i++;
		j = i;//where the space finished
		while (str[i] && str[i] != ' ' && str[i] != '\r' && str[i] != '\t')//skip other letter in a sub
			i++;
		if (i > j)//if there is letters in a sub, coz i moved forward, since j is at the end of space
		{
			subs_array[k] = (char *) malloc(sizeof(char) * (i - j) + 1);//(i - j) is length of sub
			if (subs_array[k] == NULL)
			{
				free_array(k, subs_array);
				return NULL;
			}
				
			ft_strncpy(subs_array[k], &str[j], i-j);
			k++;
		}	
		subs_array[k] = NULL;	
	}
	return (subs_array);
	
}

int main ()
{
	char * str = "  This   was hard  ";
	char copy[15] = "abc";
	char ** result = ft_split(str);
	int i = 0;
	//printf("%s\n", ft_strncpy(copy, str, 10));
	//printf("%d\n", count_substrings(str));
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return 0;
}
