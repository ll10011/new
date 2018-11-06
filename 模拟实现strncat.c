#include<stdio.h>
#include<windows.h>
#include<assert.h>
char*MyStrncat(char*str1,const char*str2, int n)
{
	assert(str1);
	assert(str2);
	char*p = str1;
	while (*str1 != 0)
	{
		*str1++;
	}
	while (*str2&&n--)
	{
		*str1++ = *str2++;
	}
	*str1 = '\0';
	return p;
}
int main()
{
	char str1[20] = "my ";
	char str2[] = "dog";
	printf("%s\n", MyStrncat(str1,str2,3));
	system("pause");
	return 0;
}