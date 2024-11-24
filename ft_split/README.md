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
		while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t')//remove initial spaces
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

Step 3:Use the count_substring to malloc for an array

Step 4: Run a while loop to do the following\
4.1. Skip initial spaces\
4.2. store the position after skipping space\
4.3. Skip other letters in a string\
4.4. if the skip space position and end letter position are different, meaning there is a substring,  malloc for a string, (protect & free) and copy that part

Step 5: Return the substrings.

See source code for more


