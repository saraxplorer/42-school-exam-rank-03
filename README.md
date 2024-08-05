**Step 1: write a simple strncpy**
``` C
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
int main ()
{
	char * str = "  At least I can count   ";
	char copy[15] = "abc";
	printf("%s", ft_strncpy(copy, str, 10));
	return 0;
}
```

**Step 2: Count Sunstrings:**
``` c
int count_substrings(char *str)
{	
	int subs_num = 0;
	int i = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t')//remove spaces including initial spaces(must be in the beginn)
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
int main ()
{
	char * str = "  At least I can count   ";
	char copy[15] = "abc";
	printf("%s\n", ft_strncpy(copy, str, 10));
	printf("%d", count_substrings(copy));
	return 0;
}
```

**Step 3:malloc for array using the subs_num**

``` c
#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
	int	count_substring = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')//remove all spaces including initial
			i++;
		if (str[i] != '\0') //If there is something in string after skipping space
		{
			count_substring++;//count 1
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\r')//skip other letters in a string
			i++;
		}
	}

	char **subs_array = (char **)malloc(sizeof(char *) * (count_substring + 1)); 
}

int main ()
{

	char * str = "  At least I can count   ";
	//printf("%d", count_substring);
	return 0;
}
```
