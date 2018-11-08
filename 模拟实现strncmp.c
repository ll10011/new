#include<stdio.h>
#include<Windows.h>
#include<assert.h> 
int MyStrcmp(char*str1, char*str2, int n)
{
	assert(str1);
	assert(str2);
	while (*str1 && *str2 && n--)
	{
		if (*str1 == *str2)
		{
			*str1++;
			*str2++;
		}
		else
			break;
	}
	if (*str1 == *str2)
	{
		return 0;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
		return -1;
}
int main()
{
	char str1[] = "abcdEf";
	char str2[] = "abcdef";
	printf("%d\n", MyStrcmp(str1, str2, 5));
	system("pause");
	return 0;
}