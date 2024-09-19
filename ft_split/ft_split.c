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
		while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t')//remove spaces: initial spaces for first round and other spaces for rest
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
	int start = 0;
	int k = 0;

	int substr_num = count_substrings(str);

	char **subs_array = (char **)malloc(sizeof(char *) * (substr_num + 1));
	if (subs_array == NULL)
		return NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')//remove initial spaces
			i++;
		start = i;//store the starting point of  a substring
		while (str[i] && str[i] != ' ' && str[i] != '\r' && str[i] != '\t')//go to the end of the substring
			i++;
		if (i > start)//if i moves ahead meaning there are char/chars in the substring
		{
			//malloc for that substring
			subs_array[k] = (char *) malloc(sizeof(char) * (i - start) + 1);//(i - start) is length of substring
			if (subs_array[k] == NULL)
			{
				free_array(k, subs_array);
				return NULL;
			}
				
			ft_strncpy(subs_array[k], &str[start], i-start); //send the start position of the str 
			k++;//move to the next substring, this line is conncted to the outer while loop
		}	//k++ MUST be inside the if block, otherwise it wont work for "abc    " case
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
