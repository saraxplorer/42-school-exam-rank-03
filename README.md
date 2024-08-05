**Step 1: Count Sunstrings:**\
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
		if (str[i] != '\0')
			count_substring++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\r')
			i++;
	}

	printf("%d", count_substring);
	return 0;
}

```
