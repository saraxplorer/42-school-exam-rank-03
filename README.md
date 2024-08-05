**Step 1: Count Sunstrings:**
``` c
#include <stdlib.h>
#include <stdio.h>



int main ()
{
	char * str = "      At least I can count   ";
	int	count_substring = 0;
	int i = 0;

	while (str[i] != '\0')
	{
    //first remove all spaces, the following while does that, but it must be in the beginning to get rid of potential initial spaces
    //If this loop comes later, the initial spaces will not be removed
  		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
			i++;
		if (str[i] != '\0') //If there is something in string after skipping space
		{
			count_substring++;//count 1
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\r')//skip other letters in a string
			i++;
		}
	}

	printf("%d", count_substring);
	return 0;
}

```
** Step 2:malloc for array**
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
